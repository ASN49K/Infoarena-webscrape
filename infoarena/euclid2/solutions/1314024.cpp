#include <fstream>
using namespace std;
ifstream fi ("euclid2.in");
ofstream fo ("euclid2.out");

int gcd (int a, int b)
{
	if (a==0)
		return b;
	if (b==0)
		return a;
	if (a%b==0)
		return b;
	return gcd (b, b%a);
}

int n,x,y;

int main ()
{
	fi>>n;
	for (int i=1;i<=n;i++)
	{
		fi>>x>>y;
		fo<<gcd(x,y)<<"\n";
	}
	fi.close();
	fo.close();
	return 0;
}