//2615 오목
// 중복 방문을 해야하는 경우가 생기므로 visited를 쓸 수 없음
// visited 대신 방향에 반대 방향 돌을 확인함으로 분기의 수를 줄임 
// 맵이 1부터 시작하기 때문에 전역변수로 맵을 생성시 패딩이 되어있으므로 6번째 돌이 맵 바깥으로 나가도 문제 없음

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
			//돌이 없는 경우 
			if(map[i][j] == 0) continue;
			//if(visited[i][j] == 1) continue;쓰면 안됨 현 정점에서 다른 방향으로 연결되어 있을 수도 있음 
			
			//i, j = y, x 좌표
			for(int k=0; k<4; k++)
			{
				if(map[i][j] == map[i-diry[k]][j-dirx[k]]) continue; //이전에 이 노드를 검사한 적이 있다면 넘어감 
				
				int new_y = i;
				int new_x = j;
				int prev = map[i][j];
				for(int l=0; l<5; l++) // 6번째까지 확인 
				{
					new_y += diry[k];
					new_x += dirx[k];
					//여섯번째가 밖으로 나가는 경우를 대비, 어차피 패딩이 되어있으므로 상관하지 말자 
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
