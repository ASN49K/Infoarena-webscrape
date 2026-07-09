#include <fstream>
using namespace std;

int gcd(int a, int b)
{
    if(!b)
          return a;
    else
          return gcd(b,a%b);
}
int main()
{
	long a,b,t,i;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>t;
	for(i=1;i<=t;i++)
	{
		f>>a>>b;
		g<<gcd(a,b)<<"\n";
	}
	f.close();
	g.close();
}
