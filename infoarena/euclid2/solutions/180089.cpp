#include<iostream.h>
#include<fstream.h>
main()
{
int t,aux,a,b;
fstream f("euclid2.in",ios::in),g("euclid2.out",ios::out);
f>>t;
for(i=1;i<=t;i++)
	{
	f>>a>>b;
	while(b!=0)
		{
		aux=b;
		b=a%b;
		a=aux;
		}
	g<<a;
	f.close();g.close();
	}