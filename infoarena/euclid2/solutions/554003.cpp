#include<iostream.h>
#include<fstream.h>
long long t,i,a,b,aux,r,n;

	
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>t;
	for(i=1;i<=t;i++)
	{
		f>>a>>b;
		r=a%b;
	while(b!=0)
	{
		r=b;
		b=a%b;
		a=r;
	}
	g<<a<<endl;
	}
	f.close();
g.close();
return 0;
}