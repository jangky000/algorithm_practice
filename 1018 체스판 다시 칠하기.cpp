#include<iostream>
#include<cstdio> 

#define INF 0xffffff

using namespace std;

int N, M;
int board[55][55];

int bmin = INF;
int init_color;

/*
0,0 ��� ¦   0,1 ������ Ȧ 0,2 ��� ¦   0, 3 ������ Ȧ  
1,0 ������ Ȧ 1,1 ��� ¦   1,2 ������ Ȧ 1,3 ��� ¦ 
*/

int Square(int r, int c)
{
	int cnt = 0;
	int rcnt = 0;
	for(int i = 0+r; i<8+r; i++)
	{
		for(int j = 0+c; j<8+c; j++)
		{
			if(i == 0+r && j == 0+c)
			{
				init_color = board[i][j];
			}
			else
			{
				if( (i-r+j-c)%2 == 0)
				{
					if(board[i][j] != init_color)
						cnt++;
					else
						rcnt++;
				}
				else if( (i-r+j-c)%2 == 1)
				{
					if(board[i][j] == init_color)
						cnt++;
					else
						rcnt++;
				}
			}
		}
	}
	if(cnt < rcnt)
		return cnt;
	else
		return rcnt+1; // ùĭ�� �ٲٴ� ��� �߰� 
}



void Check_Min()
{	
	for(int i = 0; i<=N-8; i++)
	{
		for(int j = 0; j<=M-8; j++)
		{
			int tmp = Square(i, j);
			if( bmin > tmp)
				bmin = tmp;
		}
	}
}

int main()
{
	cin >> N >> M;
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			scanf("%c", &board[i][j]);
			if(board[i][j] == '\n') // '\0' �ƴ� 
				j--;	
		}
	}
	
	Check_Min();
	
	cout << bmin << endl;	
	
	return 0;	
} 
