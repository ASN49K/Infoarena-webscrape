#include <fstream>
#define ll long long
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int t;
long long a,b;
ll cmmdc(ll a,ll b)
{
    ll r;
    while (b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    fin>>t;
    while (t--)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
