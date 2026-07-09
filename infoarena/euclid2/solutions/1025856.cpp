#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
unsigned cmmdc(unsigned a, unsigned b)
{  unsigned r=a%b;
    while(r!=0)
       {
         a=b;
         b=r;
         r=a%b;
	}
return b;
}
int main()
{
	unsigned n,a,b,i,p;
	f>>n;
	for(i=1;i<=n;i++)
		{
			f>>a>>b;
			p=cmmdc(a,b);
			g<<p<<"\n";
	}
	f.close();
	g.close();
	return 0;
	}