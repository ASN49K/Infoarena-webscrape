#include<iostream>
#include<fstream>
using namespace std;

fstream f("euclid2.in",ios::in);
fstream g("euclid2.out",ios::out);
int cmmdc(int a, int b);

void citeste()
{
	int t;
	f>>t;
	for(int i=1;i<=t;i++)
	{
		int a,b;
		f>>a>>b;
		g<<cmmdc(a,b)<<" ";
	}
}

int cmmdc(int a, int b)
{
	int r=a/b;
	while(b)
	{
		a=b;
		b=r;
		r=a/b;
	}
	return a;
}

int main()
{
	citeste();
}