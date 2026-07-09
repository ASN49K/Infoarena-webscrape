#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long a,i,b,t,r,d;
int main()
{
	f>>t;
	for(i=1;i<=t;i++)
	{f>>a>>b;
	if(a<b) r=a;
	else r=b;
	while(r!=0)
	{d=r;
	r=a%b;
	a=b;
	b=r;}
	if(d<0) d*=-1;
	g<<d<<"\n";}
	f.close();g.close();
	return 0;
}
