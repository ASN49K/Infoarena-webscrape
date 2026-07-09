#include<fstream.h>
#include<stdlib.h>

int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	int a,b,tmp;
	fin>>a>>b;
	while(b!=0)
	{
		tmp=a%b;
		a=b;
		b=tmp;

	}
	fout<<a;
	return 0;
}