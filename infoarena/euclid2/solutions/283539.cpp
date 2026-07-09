#include<fstream.h>
int n,a,b;
int cmmdc(int a,int b)
{
if (!b) return a;
return cmmdc(b,a%b);
}
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
int i;
f>>n;
for (i=0;i<n;i++)
	{
	f>>a>>b;
	g<<cmmdc(a,b)<<'\n';
	}
f.close();
g.close();
return 0;
}
