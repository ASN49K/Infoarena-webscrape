#include<iostream.h>
#include<fstream.h>
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	unsigned long long a,b,r; unsigned long i,t; f>>t;
	for (i=1;i<=t;i++)
	{
		f>>a>>b;
		r=a%b;
		while (r!=0) {a=b; b=r; r=a%b;}
		g<<b<<endl;
	}
}