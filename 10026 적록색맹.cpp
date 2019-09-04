#include<iostream>
#include<cstdio>
#include<string.h>>

using namespace std;

int n; 
int arr[105][105];
int visited[105][105];
int color_class;
int diry[] = {0, 0, 1, -1};
int dirx[] = {1, -1, 0, 0};

void DFS(int y, int x, int color)
{
	if(visited[y][x] == 1)
		return;
		
	visited[y][x] = 1;
	
	for(int i=0; i<4; i++)
	{
		int new_y = y+diry[i];
		int new_x = x+dirx[i];
		if(new_y <0 || new_y >= n) continue;
		if(new_x <0 || new_x >= n) continue;
		if(arr[new_y][new_x] != color) continue;
		
		DFS(new_y, new_x, color);
	}
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%c", &arr[i][j]);
			if(arr[i][j] == '\n')
				j--;
		}
	}
	
	for(int i = 0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(visited[i][j] != 1)
				color_class++;
				
			DFS(i, j, arr[i][j]);
			
		}
	}
	
	cout<<color_class<<" ";
	
	for(int i = 0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(arr[i][j] == 'G')
				arr[i][j] = 'R';
		}
	}
	
	memset(visited, 0, sizeof(visited)); // 2차원 배열도 한번에 초기화 가능 
	
	color_class = 0;
	
	for(int i = 0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(visited[i][j] == 0)
				color_class++;
				
			DFS(i, j, arr[i][j]);
			
		}
	}
	
	cout << color_class<<endl;
	return 0;
}
