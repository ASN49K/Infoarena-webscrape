#include<fstream>
using namespace std;
long n,m,t,i;
int cmmdc(int x,int y)
{
	int r;
	r=x%y;
	while(r)
	{
		x=y;
		y=r;
		r=x%y;
	}
	return y;
}
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>t;
	for(i=1;i<=t;i++)
	{
		f>>n>>m;
		g<<cmmdc(n,m)<<"\n";
		
	}
	return 0;
}

	