#include<fstream.h>
int main ()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int T,a,b,rest;
f>>T;
while(f>>a>>b)
	{rest=a%b;
	while(rest!=0)
		{a=b;
		b=rest;
		rest=a%b;
		}
	g<<b<<"\n";
	}
f.close();
g.close();
return 0;
}