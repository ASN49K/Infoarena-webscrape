#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	long long int r,i,j,a,b,t,aux;
	fstream f("euclid2.in",ios::in);
	fstream g("euclid2.out",ios::out);
	f>>t;
	for(i=1;i<=t;i++)
	{
		f>>a>>b;
		if(a>b)
		{
			aux=a;
			a=b;
			b=aux;
		}
		for(j=a;j<=b;j++)
		{
			r=a%b;
			while(r!=0)
			{
				a=b;
				b=r;
				r=a%b;
			}
			g<<b<<"\n";
		}
	}
	f.close();
	g.close();
	return 0;
}
