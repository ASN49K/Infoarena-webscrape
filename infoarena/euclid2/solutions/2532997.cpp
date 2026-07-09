#include <fstream>

using namespace std;

typedef long long ll;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int t;
ll a, b;

ll cmmdc(ll a, ll b)
{
    ll r;
    while(b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    in>>t;
    for(int i = 1;i <= t;i++)
    {
        in>>a>>b;
        out<<cmmdc(a, b)<<'\n';
    }
    return 0;
}
