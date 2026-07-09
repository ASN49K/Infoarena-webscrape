#include<fstream.h>
int a, b, x;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

void cmmdc(int a, int b)
{       if(a==0)
		return b;
	if(b==0)
		return a;
	if(a!=b)
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