#include<fstream.h>
unsigned long a, b, x;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

void cmmdc(unsigned long a, unsigned long b)
{	if(a!=b)
		if(a>b)
			cmmdc(a-b, b);
		else
			cmmdc(a, b-a);
	else
		x=a;
}

int main()
{       f>>a>>b;
	cmmdc(a, b);
	if(x==1) g<<0;
	else g<<x;
	g.close();
	return 0;
}