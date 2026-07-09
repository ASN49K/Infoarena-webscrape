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
    ifstream fin ("nim.in");
    ofstream fout ("nim.out");
    int teste, bit, N, XYZ;
    for (fin >> teste; teste; teste--) {
            bit = 0;
            fin >> N;
            rep (i, 1, N) fin >> XYZ, bit ^= XYZ;
            if (bit == 0) {
                    fout << "NU\n";
            continue;
            }
            fout << "DA\n";
    }
    return 0;


}
