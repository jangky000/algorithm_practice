//2615 ����
// �ߺ� �湮�� �ؾ��ϴ� ��찡 ����Ƿ� visited�� �� �� ����
// visited ��� ���⿡ �ݴ� ���� ���� Ȯ�������� �б��� ���� ���� 
// ���� 1���� �����ϱ� ������ ���������� ���� ������ �е��� �Ǿ������Ƿ� 6��° ���� �� �ٱ����� ������ ���� ����

#include<iostream>

using namespace std;

int map[25][25];

int diry[] = {0, 1, 1, -1};
int dirx[] = {1, 0, 1, 1};

void Who_Win(){
	for(int j=1; j<=19; j++)
	{
		for(int i=1; i<=19; i++)
		{
			//���� ���� ��� 
			if(map[i][j] == 0) continue;
			//if(visited[i][j] == 1) continue;���� �ȵ� �� �������� �ٸ� �������� ����Ǿ� ���� ���� ���� 
			
			//i, j = y, x ��ǥ
			for(int k=0; k<4; k++)
			{
				if(map[i][j] == map[i-diry[k]][j-dirx[k]]) continue; //������ �� ��带 �˻��� ���� �ִٸ� �Ѿ 
				
				int new_y = i;
				int new_x = j;
				int prev = map[i][j];
				for(int l=0; l<5; l++) // 6��°���� Ȯ�� 
				{
					new_y += diry[k];
					new_x += dirx[k];
					//������°�� ������ ������ ��츦 ���, ������ �е��� �Ǿ������Ƿ� ������� ���� 
					//if(new_y < 1 || new_y > 19 || new_x < 1 || new_x > 19) break;
										
					if(l == 4)
					{
						if(prev != map[new_y][new_x]){
							cout << prev << endl;
							cout << i << " " << j << endl;
							return;
						}
					}
					else{
						if(prev != map[new_y][new_x]) break;
					}
				}
			}
		}
	}
	cout << 0 <<endl;
}

int main()
{
	for(int i=1; i<=19; i++)
	{
		for(int j=1; j<=19; j++)
		{
			cin >> map[i][j];
		}
	}
	
	Who_Win();
	
	return 0;
}
