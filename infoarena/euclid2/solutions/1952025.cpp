#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long n,a,b;
long cmmdc(long a,long b)
{
    long r=a%b;
    while(r)
    {a=b;
    b=r;
    r=a%b;
    }
    return b;
}
int main()
{   long i;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
return 0;
}