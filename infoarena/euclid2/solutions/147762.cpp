#include<fstream.h>
long a,b;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
	f>>a>>b;
	while(b!=a)
	{
	  if(a>b)
	  a-=b;
	  else
	  b-=a;
	}
g<<a<<'\n';
f.close();
g.close();
return 0;
}