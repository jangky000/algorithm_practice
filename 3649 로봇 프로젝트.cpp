//런타임 오류 코드
/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int x, n;
	while(scanf("%d\n%d", &x, &n) == 2){
		vector<int> blocks;
		
		for(int i=0; i<n; i++){
			int tmp;
			cin >> tmp;
			blocks.push_back(tmp);
		}
		
		sort(blocks.begin(), blocks.end());
		
		int st = 0;
		int ed = n-1;
		
		while(st < ed){
			int sum  = blocks[st] + blocks[ed];
			if(sum == x*10000000) break;
			else if(sum < x*10000000 ) st++;
			else ed--;
		}
		
		if(st >= ed){
			cout << "danger";
		}
		else{
			cout << "yes ";
			cout << blocks[st];
			cout << " ";
			cout << blocks[ed];
			cout << endl;
		}
		
	}
	return 0;
}
*/

//성공 코드
// 알고리즘 구조 자체는 위와 같다.. 
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int x, n;
	
	while(scanf("%d\n%d", &x, &n) == 2){//
		vector<int> blocks(n);//
		x *= 10000000;//
		for(int i=0 ; i<n; i++)
		{
			scanf(" %d", &blocks[i]);//
		}
		sort(blocks.begin(), blocks.end());
		
		int st = 0, ed = n-1;
		while(st < ed)
		{
			int sum = blocks[st] + blocks[ed];
			if(sum == x) break;
			else if(sum < x) st++;
			else ed--;
		}
		
		if(st >= ed){
			printf("danger\n");
		}
		else{
			printf("yes %d %d\n", blocks[st], blocks[ed]);
		}
		
	}
	
	return 0;
} 

