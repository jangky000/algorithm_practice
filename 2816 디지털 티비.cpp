//����� ���� -> ���� �������̹Ƿ� �ƹ��ų� Ǯ�� �ȴ�. 

/*
3
MBC
KBS1
KBS2

2
KBS2
KBS1

4
MBC
SBS
KBS2
KBS1

*/

//�׽�Ʈ ���̽� ���� ����� ���� �ѹ��� ���ߴ� �����ϱ�*** 

#include<iostream>
#include<cstring>

using namespace std;

int N; 
string channel[105];

int main()
{
	int k1 = 0;
	int k2 = 0;
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> channel[i];
		if(channel[i] == "KBS1") k1 = i;
		else if(channel[i] == "KBS2") k2 = i;
	}
	
//	cout << k1 << endl << k2 << endl;
	
	//k1�� ��ġ�� �̵����� ���� �̵�
	for(int i=0; i<k1; i++) cout<<"1";
	for(int i=0; i<k1; i++) cout<<"4";
	
	
	if(k1 > k2)
	{
		if(k2 == 0) return 0;
		for(int i=0; i<k2+1; i++) cout<<"1";
		for(int i=0; i<k2; i++) cout<<"4";
	}
	
	else
	{
		if(k2 == 1) return 0;
		for(int i=0; i<k2; i++) cout<<"1";
		for(int i=0; i<k2-1; i++) cout<<"4";
	}

	return 0;
}
