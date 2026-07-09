#include <bits/stdc++.h>
#define NMax 1025
#define INF 0x3f3f3f3f
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, a[NMax], b[NMax], dp[NMax], nr;

int main()
{

    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        f >> a[i];
    for(int i = 1; i <= m; ++i)
        f >> b[i];

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(a[i] == b[j]) dp[++nr] = a[i];

    g << nr << '\n';

    for(int i = 1; i <= nr; ++i)
        g << dp[i] << " ";

    return 0;
}
