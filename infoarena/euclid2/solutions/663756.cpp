#include<fstream>
using namespace std;
int n,m,i,x,y;
int cmmdc(int a,int b)
{
	int r;
	r=a%b;
	while(r)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>n;
	for(i=1;i<=n;i++)
	{
		f>>x>>y;
		g<<cmmdc(x,y)<<"\n";
	}
	return 0;
}

	