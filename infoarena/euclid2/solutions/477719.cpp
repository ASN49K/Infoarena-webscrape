#include<fstream>
#include<iostream>
using namespace std;

int cmmdc(long long a, long long b)
{
	if(a%b==0)
	{
		return b;
	}
	else
	{
		return cmmdc(b, a%b);
	}
}
int main()
{
	unsigned int T;
	long long a,b;
	fstream fin("euclid2.in",fstream::in);
	fstream fout("euclid2.out",fstream::out);
	fin>>T;
	for(int i=0; i<T; i++)
	{
		fin>>a>>b;
		fout<<(a>b?cmmdc(a,b):cmmdc(b,a))<<"\n";
	}
	fin.close();
	fout.close();
	return 0;
}
