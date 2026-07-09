#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
unsigned int cmmdc(unsigned int x,unsigned int y)
{
	int r;
	while(r)
	{
		r=x%y;
		x=y;
		y=r;
	}
	return x;
}

int main ()
{
	int T,a,b,d,i;
	f>>T;
	for(i=1;i<=T;i++)
	{
		f>>a>>b;
		d=cmmdc(a,b);
		g<<d<<'\n';
	}
	f.close();
	g.close();
	return 0;
}