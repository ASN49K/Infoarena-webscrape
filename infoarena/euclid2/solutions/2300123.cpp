#include <fstream>
#include <cmath>

using namespace std;

long a,i,b,n;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

void cmmdc()
{
    long long r;
    while( b )
			{
            r = a % b;
			a = b;
			b = r;
			}
		g<<a<<endl;
}

int main()
{
f>>n;
for(i=1;i<=n;i++)
{
f>>a>>b;
cmmdc();
}
return 0;
}
