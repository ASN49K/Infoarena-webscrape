#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, dp[1030][1030];
int a[1030], b[1030];
stack <int> st;

int main()
{
    int i, j, ma;
    fin >> n >> m;
    for (i = 1; i <= n; i++)
        fin >> a[i];
    for (i = 1; i <= m; i++)
        fin >> b[i];

    for (i = n; i >= 1; i--)
        for (j = m; j >= 1; j--)
            if (a[i] == b[j])
                dp[i][j] = max({dp[i + 1][j], dp[i][j + 1], 1 + dp[i + 1][j + 1]});
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);

    fout << dp[1][1] << "\n";
    i = n;
    j = m;
    while (i >= 1 and j >= 1)
    {
        if (a[i] == b[j])
            st.push(a[i]);
        if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    while (!st.empty())
    {
        fout << st.top() << " ";
        st.pop();
    }
    fout.close();
    return 0;
}
