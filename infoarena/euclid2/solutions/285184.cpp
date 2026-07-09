#include <fstream>
using namespace std;

int gcd(int a, int b)
{
    if(a==b)
            return a;
    else
        if(a<b)
               return gcd(a,b-a);
        else
            if(a>b)
                   return gcd(a-b,b);
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
		g<<gcd(a,b);
	}
	f.close();
	g.close();
}
