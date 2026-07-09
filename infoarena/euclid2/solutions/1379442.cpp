/*
    Keep It Simple!
*/

#include <fstream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int cmmdc(int a,int b)
{
    if(!b) return a;
    return cmmdc(b,a%b);
}

void Solve()
{
    int t,x,y;
    f >> t;
    while(t--)
    {
        f >> x >> y;
        g << cmmdc(x,y) << '\n';
    }
}

int main()
{
    Solve();
    return 0;
}
