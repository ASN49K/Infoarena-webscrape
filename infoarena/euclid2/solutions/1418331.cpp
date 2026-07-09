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

#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define whatis(x) cerr << #x << " is " << x;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

void Solve()
{
    int T;
    ios::sync_with_stdio(false);
    fin >> T;
    while (T--) {
        int x, y;
        fin >> x >> y;
        fout << __gcd(x,y) << '\n';
    }
}

int main()
{
    Solve();
    return 0;
}
