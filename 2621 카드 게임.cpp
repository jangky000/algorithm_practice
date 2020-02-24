//걍 노가다 

#include<iostream>

using namespace std;

int color[5]; // R0, B1, Y2, G3
int num_arr[11] = {0, }; //1~9
int seq[5][10] = 	{ // 2차원 배열에서 1차원 배열의 크기를 넉넉하게 잡으면 행이 엉망이 되어버려서 문제*** 
							0, 1, 1, 1, 1, 1, 0, 0, 0, 0,
							0, 0, 1, 1, 1, 1, 1, 0, 0, 0,
							0, 0, 0, 1, 1, 1, 1, 1, 0, 0,
							0, 0, 0, 0, 1, 1, 1, 1, 1, 0,
							0, 0, 0, 0, 0, 1, 1, 1, 1, 1
						};

typedef struct{
	int num;
	int index;
}Max_Result;

/*
	if 5개 같은 색
		if 숫자 연속적 900
		else  600
	else if 4개 숫자 같은: 800
	else if 3개 숫자 같은 
		if 2장 숫자 같은: 700
		else: 400 
	else if  5장 숫자 연속적 500
	else if 2개 같은 숫자:
		if 다른 2개 같은 숫자: 300
		else: 200
	else: 100
*/

Max_Result same_color()
{
	Max_Result tmp = {0, };
	int max = 0;
	int index = 0;
	for(int i=0; i<4; i++)
	{
		if(color[i] > max)
		{
			max = color[i];
			index = i;
		}
	}
	tmp.num = max;
	tmp.index = index;
	return tmp;
}



int continue_num()
{
	for(int i=0; i<5; i++)
	{
		int j;
		for(j = 1; j<=9; j++)
		{
			if(num_arr[j] != seq[i][j]) break;
		}
		if(j == 10) return i+5;
	}
	return 0;
}

Max_Result same_num()
{
	Max_Result tmp = {0, };
	
	for(int i=1; i<=9; i++)
	{
		if(num_arr[i] > tmp.num)
		{
			tmp.num = num_arr[i];
			tmp.index = i;
		}
	}
	
	return tmp;
}

int find_another_same_num(int max, int index)
{
	for(int i=index+1; i<=9; i++)
	{
		if(num_arr[i] == max)
			return i;
	}
	return 0;
}

int find_max_num()
{
	int  max;
	for(int i = 1; i<=9; i++)
	{
		if(num_arr[i] > 0)
		{
			max = i;
		}
	}
	return max;
}

int main()
{

	char input_col;
	int input_num;
	
	Max_Result same_color_result = {0, };
	Max_Result same_num_result = {0, };
	int continue_num_result = 0;
	int max_num_result = 0;
	
	for(int i=0; i<5; i++)
	{
		cin >> input_col;
		if(input_col == 'R') color[0]++;
		else if(input_col == 'B') color[1]++;
		else if(input_col == 'Y') color[2]++;
		else if(input_col == 'G') color[3]++;
			
		cin >> input_num;
		num_arr[input_num]++;

	}
	
//	for(int i=1; i<=9; i++)
//	{
//		cout << num_arr[i]<<endl;
//	}
	
		
	same_color_result = same_color();
	same_num_result = same_num();
	continue_num_result = continue_num();
	max_num_result = find_max_num();
	
	if(same_color_result.num == 5)
	{
		if(continue_num_result)
		{
			//900
			cout << continue_num_result + 900 << endl;
		}
		else{
			// 가장 큰 숫자 + 600
			cout << max_num_result + 600;
		}
	}
	else if(same_num_result.num == 4)
	{
		//800
		cout << same_num_result.index + 800;
	}
	else if(same_num_result.num == 3)
	{
		//700 if / else 400
		int tmp = find_another_same_num(2, 0);
		if(tmp)
		{
			cout << 10*same_num_result.index + tmp + 700;
		}
		else cout << same_num_result.index + 400;
	}
	else if(continue_num_result)
	{
		//500
		cout << continue_num_result + 500;
	}
	else if(same_num_result.num == 2)
	{
		//if 300 / else 200
		int tmp = find_another_same_num(2, same_num_result.index);
		if(tmp)
		{
			cout << 10*tmp + same_num_result.index + 300;
		}
		else cout << same_num_result.index + 200;
	}
	else
	{
		//100
		cout << max_num_result + 100;
	}
	
	
	return 0;
}
