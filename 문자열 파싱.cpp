#include<iostream>
#include<cstring>

using namespace std;

char str1[100] = "a,b,c,d,e";

int main()
{
	char* tok1 = strtok(str1, ",");
	
	while(tok1 != NULL)
	{
		cout << tok1 << endl;
		//NULL�� �־��ָ�, static ���� old�� ����Ͽ� ��� �Ľ��Ѵ�. 
		tok1 = strtok(NULL, ",");
	}
	return 0;
}
