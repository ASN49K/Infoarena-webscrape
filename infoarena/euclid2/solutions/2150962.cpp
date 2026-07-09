#include <fstream>
#define ll long long
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
ll cmmdc (ll x,ll y)
{
    ll z;
    while(y)
    {
        z=x%y;
        x=y;
        y=z;
    }
    return x;
}
ll n,i,a,b;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
