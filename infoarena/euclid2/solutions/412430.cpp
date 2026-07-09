#include<fstream.h>
ifstream f("cmmdc.in");
ofstream g("cmmdc.out");
long a,b,r;
int main()
{
	f>>a>>b;
	r=a%b;
	while (r!=0)
	{ a=b;
	  b=r; 
	  r=a%b;
	}
	if (b!=1)
		g<<b;
	else 
		g<<0;
	return 0;
}
