#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,i,a,b;
int cmmdc(int a,int b)
{
	int r=a%b;
	while(r!=0)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
int main()
{
	f>>t;
	for(i=1;i<=t;i++)
	{
		f>>a>>b;
		g<<cmmdc(a,b)<<"\n";
	}
	return 0;
}
