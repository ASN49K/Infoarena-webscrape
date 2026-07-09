#include <fstream>

using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
long n,i,a,b;
long cmmdc (long a,long b)
{   int d=a,i=b,r=d%i;
    while (r)
    {   d=i;
        i=r;
        r=d%i;
    }
 	return i;
}
int main()
{   f>>n;
    for (i=1;i<=n;i++)
    {f>>a>>b;g<<cmmdc(a,b)<<'\n';}
    return 0;
}
