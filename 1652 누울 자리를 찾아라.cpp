// ���� �߰� ����: 
// 2ĭ �̻��� 1���� ī��Ʈ
// (2ĭ, 3ĭ, 4ĭ ���� �ϳ��� ĭ���� ī��Ʈ)

#include<iostream>
#include<cstring>

using namespace std;

int N; // 1 ~ 100
int h, v;

char map[110][110];

int hor[110][110];
int ver[110][110];


// ���� ���� ���ؼ� ���ϸ� �� 

int main()
{
	cin >> N;
	
	for(int i=1; i<=N; i++)
		cin >> &map[i][1]; // string���� �Է� & ���ڿ� ���� ��ġ�� [1]�� �ּҷ� ����***
		
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
