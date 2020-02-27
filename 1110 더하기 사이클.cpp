//26 -> 68 -> 84 -> 42 -> 26
//DFS
#include<iostream>

using namespace std;

int N;
int digit[2];

void DFS(int d1, int d0, int n)
{
	int nd1=0;
	int nd0=0;
	
	if(n!=0 && digit[1] == d1 && digit[0] == d0)
	{
		cout<<n<<endl;
		return;	
	}
	
	nd1 = d0;
	nd0 = (d1 + d0)%10;
	
	DFS(nd1, nd0, n+1);
}

int main()
{
	cin >> N;
	
	digit[1] = N/10;
	digit[0] = N%10;
	
	DFS(digit[1], digit[0], 0);
	
	return 0;
} 
