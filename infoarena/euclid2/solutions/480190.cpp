#include<iostream.h>
#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
	int a,x,y,i;
	f >> a;
	for (i=1; i<=a; i++)
	{
		f >> x >> y;
		while (x!=y)
			if (x>y)
				x=x-y;
			else
				y=y-x;
		
		g << y<<endl;
	}
	f.close();
	g.close();
}