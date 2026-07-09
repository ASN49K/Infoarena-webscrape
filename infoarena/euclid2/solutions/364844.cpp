#include<fstream.h>
ifstream f("cmmdc.in");
ofstream g("cmmdc.out");
int a,b,cmmdcl,r;
int main()
{
	f>>a;
	f>>b;
	r=a%b;
	while(r!=0)
	{
		a=b;
		b=r;
		r=a%b;
	}
	cmmdcl=b;
	g<<cmmdcl;
	return 0;
}