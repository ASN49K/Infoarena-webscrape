#include<iostream.h>
#include<fstream.h>
int main ()
{
	fstream f,g;
	long int a,b;
	int i,n;
	f.open("euclid2.in",ios::in);
	g.open("euclid2.out",ios::out);
	f>>n;
	for (i=0;i<n;i++)
	{
	f>>a>>b;
	while (a!=b)
	{
		if (a>b) a=a-b;
		else b=b-a;
	}
	g<<a<<'\n';
	}
	f.close();
	g.close();
}
