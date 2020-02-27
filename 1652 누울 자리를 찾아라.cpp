// 문제 추가 설명: 
// 2칸 이상을 1개로 카운트
// (2칸, 3칸, 4칸 등을 하나의 칸으로 카운트)

#include<iostream>
#include<cstring>

using namespace std;

int N; // 1 ~ 100
int h, v;

char map[110][110];

int hor[110][110];
int ver[110][110];


// 왼쪽 값에 더해서 구하면 됨 

int main()
{
	cin >> N;
	
	for(int i=1; i<=N; i++)
		cin >> &map[i][1]; // string으로 입력 & 문자열 시작 위치를 [1]의 주소로 설정***
		
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			if(map[i][j] == 'X' || map[i][j] == 'x')
			{
				hor[i][j] = ver[j][i] = 0;
			}
			else
			{
				hor[i][j] = hor[i][j-1] + 1;
				ver[j][i] = ver[j][i-1] + 1;
			}
		}
	}
	
//	for(int i=1; i<=N; i++)
//	{
//		for(int j=1; j<=N; j++)
//		{
//			cout << hor[i][j] << " ";
//		}
//		cout << endl;
//	}
//	
//	cout << endl;
//	
//	for(int i=1; i<=N; i++)
//	{
//		for(int j=1; j<=N; j++)
//		{
//			cout << ver[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			if(hor[i][j] == 2) h++;
			if(ver[i][j] == 2) v++;
		}
	}
	
	cout << h << " " << v <<endl;
		
	return 0;
}
