#include<fstream.h>
long a,b,d;
ifstream f("euclid.in");
ofstream g("euclid.out");
int main()
{
long r;
	f>>a>>b;
	while(b)
	{
	  r=a%b;
	  a=b;
	  b=r;
	}
g<<a;
f.close();
g.close();
return 0;
}