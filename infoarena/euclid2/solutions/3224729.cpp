#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int T;
int cmmdc(ll a, ll b)
{
    if(b==0)
        return a;
    return cmmdc(b, a % b);
}
int main()
{
    f >> T;
    while (T--)
    {
        ll a, b;
        f >> a >> b;
        g<<cmmdc(a, b)<<"\n";
    }
}
