#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
unsigned long long a,i,b,t,r,d;
int main()
{
	f>>t;
	for(i=1;i<=t;i++)
	{f>>a>>b;
	while(r!=0)
	{d=r;
	r=a%b;
	a=b;
	b=r;}
	g<<d<<"\n";}
	f.close();g.close();
	return 0;
}
