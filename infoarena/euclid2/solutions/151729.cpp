#include<fstream.h>
#include<stdlib.h>

int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	long a,b;
	fin>>a>>b;
	while(!b)
	{
		a=b;
		b=a%b;
	}
	fout<<a;
	return 0;
}