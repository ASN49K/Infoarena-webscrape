#include<fstream.h>
unsigned long a, b, x;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

unsigned long cmmdc(unsigned long a, unsigned long b)
{       if(a==0)
		return b;
	if(b==0)
		return a;
	if(a>b)
		return cmmdc(a%b, b);
	else
		return cmmdc(a, b%a);
}

int main()
{       f>>a>>b;
	x=cmmdc(a, b);
	g<<x;
	g.close();
	return 0;
}