#include<iostream.h>
#include<fstream.h>
int main ()
{
	fstream f,g;
	long int a,b,z;
	int i,n;
	f.open("euclid2.in",ios::in);
	g.open("euclid2.out",ios::out);
	f>>n;
	for (i=0;i<n;i++)
	{
	f>>a>>b;
	while (b!=0)
	{
		z=a;
		a=b;
		b=z%b;
	}
	g<<a<<'\n';
	}
	f.close();
	g.close();
}
