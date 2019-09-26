//1978 N번째 소수 찾기 

#include<iostream>
#include<cmath>

using namespace std;

int N;
int num[110];
int prime_check[1010];

void Find_Prime()
{
	prime_check[1] = 1;
	for(int i = 2; i<=100; i++)
	{
		if(prime_check[i] == 1) continue;
		for(int j = i*i; j <= 1000; j += i){
			prime_check[j] = 1;	
		}
	}
}

int main()
{
	cin >> N;
	
	for(int i=0; i<N; i++)
	{
		cin >> num[i]; 	
	}
	
	Find_Prime();
	int cnt = 0;
	
	for(int i=0; i<N; i++)
	{
		if(prime_check[num[i]] == 0)
			cnt++;
	}
	
	
	cout << cnt <<endl;
	return 0;
}


