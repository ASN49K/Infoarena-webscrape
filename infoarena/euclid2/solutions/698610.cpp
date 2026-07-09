#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,n,i,r;
 
int cmmdc(int x,int y)
{
	while(y!=0)
	{
		r=x%y;
		x=y;
		y=r;
	}
	return y;
}
int main()
{
	f>>n;
	for(i=1;i<=n;i++)
	{
		f>>a;
		f>>b;
		g<<cmmdc(a,b)<<'\n';
	}
	f.close();
	g.close();
	return 0;
}