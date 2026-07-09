#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
#define pb push_back

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int N = 1030;

int n, m, dp[N][N], a[N], b[N];

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; i++) fin >> a[i];
    for (int j = 1; j <= m; j++){
        fin >> b[j];
        for (int i = 1; i <= n; i++)
            dp[i][j] = (b[j] == a[i] ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]));
    }
    fout << dp[n][m] << '\n';
    int i = n, j = m, cnt = dp[n][m];
    stack<int> stk;
    while (cnt) {
        if (a[i] == b[j]){
            stk.push(a[i]);
            i--; j--;
            cnt--;
        }
        else if (dp[i-1][j] == dp[i][j]) i--;
        else j--;
    }
    while (!stk.empty()) { fout << stk.top() << ' '; stk.pop(); }

    return 0;
}
