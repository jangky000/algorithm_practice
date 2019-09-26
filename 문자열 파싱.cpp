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
		//NULL을 넣어주면, static 변수 old를 사용하여 계속 파싱한다. 
		tok1 = strtok(NULL, ",");
	}
	return 0;
}
