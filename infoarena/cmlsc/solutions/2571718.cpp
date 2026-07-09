#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int nmax = 1026;
int n, m;
int a[nmax], b[nmax];
int dp[nmax][nmax];
stack <int> st;

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int i = 1; i <= m; i++)
        fin >> b[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    fout << dp[n][m] << "\n";
    for (int i = n, j = m; i > 0;)
    {
        if (a[i] == b[j])
            st.push(a[i]), i--, j--;
        else if (dp[i-1][j] < dp[i][j-1])
            j--;
        else
            i--;
    }
    while (!st.empty())
        fout << st.top() << " ", st.pop();
    return 0;
}
