#include<iostream.h>
#include<fstream.h>
long long t,i,a,b,aux,r,n;
int cmmdc(int x, int y)
{
	if(!y) return x;
	return cmmdc(y, x%y);
}
	
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>t;
	for(i=1;i<=t;i++)
	{
		f>>a>>b;
		g<<cmmdc(a,b)<<"\n";
	}
	f.close();
g.close();
return 0;
}