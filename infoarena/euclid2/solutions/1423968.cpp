#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <bitset>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cstring>


#define ll long long
#define llu unsigned long long
#define rep(i, a, b) for (int i = (a) ; i <= (b) ; ++i)

#define mp make_pair
#define pii pair <int, int>
#define SORT(x) sort ((x).begin(), (x).end() )
#define fi first

using namespace std;

vector <int> x;

static const int inf = 2e8;

inline int gcd (ll x, ll y){
    return (!y ? x : gcd(y, x % y));
}

int main(){
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    int teste;
    ll a, b;
    for (fin >> teste; teste; teste--){
        fin >> a >> b;
    fout << gcd(a,b) << "\n";
    }

return 0;
}
