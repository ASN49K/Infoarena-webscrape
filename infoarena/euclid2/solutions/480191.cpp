#include<iostream.h>
#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
	int a,x,y,i,r;
	f >> a;
	for (i=1; i<=a; i++)
	{
		f >> x >> y;
		r=x%y;
		while (r!=0)
		{
			x=y;
			y=r;
			r=x%y;
		}
		g << y<<'n\10';
	}
	f.close();
	g.close();
}
