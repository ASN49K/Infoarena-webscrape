#include<iostream>
#include<fstream>
using namespace std;

fstream f("euclid2.in",ios::in);
fstream g("euclid2.out",ios::out);
long cmmdc(long a, long b);

void citeste()
{
	long t;
	f>>t;
	for(long i=1;i<=t;i++)
	{
		long a,b;
		f>>a>>b;
		g<<cmmdc(a,b)<<" ";
	}
}

long cmmdc(long a, long b)
{
	long r=a%b;
	while(r)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}

int main()
{
	citeste();
	return 0;
}
