#include<fstream>
using namespace std;
long x,y,n,i;
long cmmdc(long a,long b)
{
	if(!b)
		return a;
	else
		return cmmdc(b,a%b);
}
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>n;
	for(i=1;i<=n;i++)
	{
		f>>x>>y;
		if(x>y)
			g<<cmmdc(x,y)<<"\n";
		else
			g<<cmmdc(y,x)<<"\n";
	}
	return 0;
}