// 1357¹ø ¹®Á¦ µÚÁıÈù µ¡¼À 

#include<iostream>

using namespace std;

int REV(int n)
{
	int cnt = 0;
	int tmp[10];
	
	while( n )
	{
		tmp[cnt++] = n %10;
		n /= 10;
	}
	
	int reverse = 0;
	
	for(int i= 0; i<cnt; i++)
	{
		reverse *= 10;
		reverse += tmp[i];
	}
	
	return reverse;
}

int main()
{
	int n1, n2;
	cin >> n1 >> n2;
	
	cout << REV(REV(n1) + REV(n2));
		
	return 0;
} 
