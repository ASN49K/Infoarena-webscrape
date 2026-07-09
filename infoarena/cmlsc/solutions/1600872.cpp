#include <fstream>
#include <time.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <bitset>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#define pb push_back
#define mp make_pair
#define sortvi(a) sort(a.begin(), a.end())
#define FOR(i, start, final) for (int i=start; i<=final; ++i)
#define ROF(i, start, final) for (int i=start; i>=final; --i)

#define NMAX 1030

//void f(int &x){char k;for(k=getchar();k<= 32;k=getchar());for(x=0;'0'<=k;k=getchar())x=x*10+k-'0';}

/*void f(int &x)//parsare cu semn
{
	char k; bool semn=0;
	for (k = getchar(); (k>'9' || k<'0');)
    {
        if (k=='-') semn=1;
        k=getchar();
    }
	for (x = 0; '0' <= k; k = getchar())	x = x * 10 + k - '0';
    if (semn==1) x=-x;
}*/

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int, int> pi;
typedef vector< int > vi;
typedef vector< pair< int, int > > vpi;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int N, M, a[NMAX], b[NMAX], dp[NMAX][NMAX], sir[NMAX], lg;

int main()
{
    f.sync_with_stdio(false);
    f>>N>>M;
    FOR(i,1,N) f>>a[i];
    FOR(i,1,M) f>>b[i];

    FOR(i,1,N) {
        FOR(j,1,M) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    for (int i = N, j = M; i;) {
        if (a[i] == b[j]) {
            sir[++lg] = a[i];
            --i;
            --j;
        } else if (dp[i - 1][j] < dp[i][j - 1]) --j;
            else --i;
    }

    g<<lg<<'\n';
    FOR(i,1,lg) {
        g<<sir[i]<<' ';
    }
    return 0;
}
