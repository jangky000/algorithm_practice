#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

typedef struct{
	int r, c, dir, level;
} POS;

int M, N;
int map[110][110]; 
//3차원의 visited 행렬 
int visited[110][110][5];

POS st;
POS dst;

queue<POS> q;

int go_c[5] = {0, 1, -1, 0, 0};
int go_r[5] = {0, 0, 0, 1, -1};

// right 동1 -> 남3 -> 서2 -> 북4
int turn_right[5] = {0, 3, 4, 2, 1};
// left 동1 -> 북4 -> 서2 -> 남3
int turn_left[5] = {0, 4, 3, 1, 2};

int BFS()
{
	q.push(st);
	visited[st.r][st.c][st.dir] = 1;
	
	while(!q.empty())
	{
		POS tmp = q.front();
		q.pop();
		
		// 리턴 위치 주의하기 
		if(tmp.r == dst.r && tmp.c == dst.c && tmp.dir == dst.dir) return tmp.level; 
		
		for(int i=1; i<=3; i++)
		{
			POS new_tmp = {tmp.r+go_r[tmp.dir]*i, tmp.c+go_c[tmp.dir]*i, tmp.dir, tmp.level+1};
			if(new_tmp.r < 1 || new_tmp.r > M) break;
			if(new_tmp.c < 1 || new_tmp.c > N) break;
			if(map[new_tmp.r][new_tmp.c] == 1) break;
			if(visited[new_tmp.r][new_tmp.c][new_tmp.dir] == 1) continue;
			visited[new_tmp.r][new_tmp.c][new_tmp.dir] = 1;
			//if(new_tmp.r == dst.r && new_tmp.c == dst.c && new_tmp.dir == dst.dir) return new_tmp.level;
			q.push(new_tmp);
		}
		
		{
			POS new_tmp = {tmp.r, tmp.c, turn_right[tmp.dir], tmp.level+1};
			//if(new_tmp.r == dst.r && new_tmp.c == dst.c && new_tmp.dir == dst.dir) return new_tmp.level;
			if(visited[new_tmp.r][new_tmp.c][new_tmp.dir] != 1){
				visited[new_tmp.r][new_tmp.c][new_tmp.dir]=1;
				q.push(new_tmp);
			}
		}
		{
			POS new_tmp = {tmp.r, tmp.c, turn_left[tmp.dir], tmp.level+1} ;
			//if(new_tmp.r == dst.r && new_tmp.c == dst.c && new_tmp.dir == dst.dir) return new_tmp.level;
			if(visited[new_tmp.r][new_tmp.c][new_tmp.dir] != 1){
				visited[new_tmp.r][new_tmp.c][new_tmp.dir]=1;
				q.push(new_tmp);
			}
		}
	}
	
	return -1;
}


int main()
{
	cin >> M >> N;
	
	for(int i =1; i<=M; i++)
	{
		for(int j=1; j<=N; j++)
		{
			cin >> map[i][j];
		}
	}
	
	
	cin >> st.r >> st.c >> st.dir;
	cin >> dst.r >> dst.c >> dst.dir;
	
	cout << BFS() << endl;
	
	return 0;
}


