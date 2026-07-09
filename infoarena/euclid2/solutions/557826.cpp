#include<fstream.h>

ifstream fin("cmmdc.in");
ofstream fout("cmmdc.out");

int main()
{
	int a,b,r;
	fin>>a>>b;
	while(b!=0)
		{r=a%b;
		a=b;
		b=r;
}
fout<<a;
		
}