#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
int a[1030], b[1030], dp[1030][1030];
stack<int> st;

int main()
{
    int i, j;
    fin >> n >> m;
    for (i = 1; i <= n; i++)
        fin >> a[i];

    for (i = 1; i <= m; i++)
        fin >> b[i];

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    fout << dp[n][m] << "\n";
    i = n; j = m;
    while (i >= 1 && j >= 1)
    {
        if (a[i] == b[j])
        {
            st.push(a[i]);
            i--; j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
                j--;
            else
                i--;
        }
    }
    while (!st.empty())
    {
        fout << st.top() << " ";
        st.pop();
    }
    return 0;
}
