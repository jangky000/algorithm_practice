//동적 계획법 // 쿠팡 

#include<iostream>
#include<cstring>

using namespace std;

#define DI 10 
//N의 범위가 1,000,000이므로 N보다 큰 소수 하나를 더 찾아야 함**
//N이 자기 자신 포함하는지? *
#define MAX 2000000 // 1------1이 안 나오고 있다 
//#define MAX 500

int num[MAX];

int ispal(int d) 
{
	int digit[DI]; // 쓰레기 값 지우기 
	int n = 0;
	
	memset(digit, 0, DI*sizeof(int));
	
	//digit로 정리 
	//to_string()으로 간단하게 해결 가능 
	for(int i=0; i<DI; i++)
	{
		digit[i] = d%10;
		n++;
		if(d >= 10)
			d /= 10;
		else break; 
	}
	
	//pal
	int s = 0;
	int e = n-1;
	
	while(s < e)
		if(digit[s++] != digit[e--])
			return false;
	return true;
} 

void sup_init()
{
	//소수 찾기
	num[1] = 1; 
	for(int i=2; i<MAX; i++)
	{
		if(num[i] == 1) continue; 
		for(int j=i+i; j<=MAX; j+=i) // 건너뛰면서 시간 절약***
		{
				//소수가 아님 
				num[j] = 1;
		}
	}
}

int main()
{
	int N;
	cin >> N;
	 
	sup_init();
	
	for(int i=2; i<MAX; i++)
		if( !num[i] && ispal(i))
			if(i >= N)
			{
				cout << i << endl;
				break;
			}
	
//	cout << ispal(100) << endl;
	
		
	return 0;
}
