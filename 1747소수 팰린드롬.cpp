//���� ��ȹ�� // ���� 

#include<iostream>
#include<cstring>

using namespace std;

#define DI 10 
//N�� ������ 1,000,000�̹Ƿ� N���� ū �Ҽ� �ϳ��� �� ã�ƾ� ��**
//N�� �ڱ� �ڽ� �����ϴ���? *
#define MAX 2000000 // 1------1�� �� ������ �ִ� 
//#define MAX 500

int num[MAX];

int ispal(int d) 
{
	int digit[DI]; // ������ �� ����� 
	int n = 0;
	
	memset(digit, 0, DI*sizeof(int));
	
	//digit�� ���� 
	//to_string()���� �����ϰ� �ذ� ���� 
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
	//�Ҽ� ã��
	num[1] = 1; 
	for(int i=2; i<MAX; i++)
	{
		if(num[i] == 1) continue; 
		for(int j=i+i; j<=MAX; j+=i) // �ǳʶٸ鼭 �ð� ����***
		{
				//�Ҽ��� �ƴ� 
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
