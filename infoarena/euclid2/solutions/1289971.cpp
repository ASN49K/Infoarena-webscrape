#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;

#define dbg(x) (cout<<#x<<" = "<<(x)<<'\n')
const string problemName = "euclid2";
const string inputFile = problemName + ".in";
const string outputFile = problemName + ".out";

typedef long long int lld;
typedef pair<int, int> PII;
typedef pair<int, lld> PIL;
typedef pair<lld, int> PLI;
typedef pair<lld, lld> PLL;

const int INF = (1LL << 31) - 1;
const lld LINF = (1LL << 62) - 1;
const int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
const int MOD = (int)(1e9) + 7;

const int NMAX = 100000 + 5;
const int MMAX = 100000 + 5;
const int KMAX = 100000 + 5;
const int PMAX = 100000 + 5;
const int LMAX = 100000 + 5;
const int VMAX = 100000 + 5;

int T;

int main() {
    int a, b;

#ifndef ONLINE_JUDGE
    freopen(inputFile, "r", stdin);
    freopen(outputFile, "w", stdout);
#endif

    scanf("%d", &T);

    while(T--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", __gcd(a, b));
    }

    return 0;
}
