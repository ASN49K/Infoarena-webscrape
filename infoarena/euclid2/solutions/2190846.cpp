#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,i;
long long a,b;
long long cmmdc(long long x, long long y)
{
    int r=x%y;
    while(r!=1)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int main()
{
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
