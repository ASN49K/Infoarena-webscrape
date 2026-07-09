#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <iomanip>
#include <vector>

#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
typedef long long ll;
const ll Nmax=1e6+5, inf=1e9+5;
using pll=pair<ll, ll>;

int t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fin>>t;
    int a, b;
    for (int i=0; i<t; i++){
        fin>>a>>b;
        fout<<__gcd(a, b)<<'\n';
    }
    return 0;
}
