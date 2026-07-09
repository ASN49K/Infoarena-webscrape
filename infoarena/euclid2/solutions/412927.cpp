#include<fstream.h>
int n,i,e1,e2;
int euclid(int a,int b)
{
	if(!b) return a;
	return euclid(b,a-b*(a/b));
}
	
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>n;
	for(i=1;i<=n;i++)
	{
		f>>e1>>e2;
		g<<euclid(e1,e2)<<'\n';
	}
}