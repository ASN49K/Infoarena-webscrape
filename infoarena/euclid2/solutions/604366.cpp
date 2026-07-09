#include<iostream.h>
#include<fstream.h>

int cmmdc(long int a,long int b)
{
	if(a==b)
		return a;
	else
		if(a>b)
			return cmmdc(a-b,b);
		else
			return cmmdc(a,b-a);
}
int main()
{
	long int a,b;
	int n,i;
	
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");

	f>>n;
	for(i=1;i<=n;i++)
	{
		f>>a;
		f>>b;
		g<<cmmdc(a,b);
		if(i!=n)
			g<<endl;
	}
	
	return 0;
}