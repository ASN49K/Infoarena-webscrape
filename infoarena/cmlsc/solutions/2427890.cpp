/*
* @Author: Cristi Cretan
* @Date:   02-06-2019 17:40:00
* @Last Modified by:   Cristi Cretan
* @Last Modified time: 02-06-2019 17:57:54
*/
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
// #define f cin
// #define g cout
#define dbg(x) cerr<<#x<<" = "<<x<<endl;
#define dbg_v(v,n) {cerr<<#v<<" = [";for(int III=1;III<=n;III++)cerr<<v[III]<<(III!=n?",":"]\n");}
#define ll long long
#define ld long double
#define pii pair<int,int>
#define MOD 1000000007
#define zeros(x) x&(x-1)^x
#define NMax 1027
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int A, B;
int a[NMax], b[NMax], dp[NMax][NMax];

int main()
{
    f >> A >> B;

    for (int i = 1; i <= A; ++i)
        f >> a[i];
    for (int i = 1; i <= B; ++i)
        f >> b[i];

    for (int i = 1; i <= A; ++i)
        for (int j = 1; j <= B; ++j)
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    g << dp[A][B] << '\n';

    int i_curent = A;
    int j_curent = B;

    int ans[NMax], k = 0;

    while(i_curent) {
        if (a[i_curent] == b[j_curent]) {
            ans[k++] = a[i_curent];
            i_curent--;
            j_curent--;
        }
        if (dp[i_curent - 1][j_curent] < dp[i_curent][j_curent - 1]) --j_curent;
        else --i_curent;
    }

    for (int i = k - 1; i >= 0; --i)
        g << ans[i] << (i != 0 ? ' ' : '\n');
    return 0;
}