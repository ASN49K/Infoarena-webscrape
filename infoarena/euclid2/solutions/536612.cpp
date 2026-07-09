#include<iostream.h>
#include<fstream.h>
int main()
{
	int T,i,a,b,c;
	ifstream f("euclid.in");
	ofstream g("euclid.out");
	f>>T;
	for (i=0;i<T;i++)
	{
		f>>a;
		f>>b;
		do
		{
			c=a%b;
			a=b;
			b=c;
		} while (c);
		g<<a<<"\n";
	}
	return 0;
}