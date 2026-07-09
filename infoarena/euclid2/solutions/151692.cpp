#include<fstream.h>

int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	int a,b,div;
	fin>>a>>b;
	while(a!=b)
	{
		if(a>b) a=a-b;
		else b=b-a;
	}
	fout<<a;
	return 0;
}