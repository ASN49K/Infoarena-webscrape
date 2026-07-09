#include <bits/stdc++.h>

using namespace std;

int n, m, a[1030], b[1030];
int dp[1030][1030];
stack <int> st;

int main()
{
    int i, j;
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");

    cin >> n >> m;

    for (i = 1; i <= n; i++)
        cin >> a[i];

    for (i = 1; i <= m; i++)
        cin >> b[i];

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        if (a[i] == b[j])
            dp[i][j] = 1 + dp[i - 1][j - 1];
        else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    cout << dp[n][m] << "\n";

    i = n;
    j = m;
    while (i >= 1 and j >= 1)
    {
        if (a[i] == b[j])
        {
            st.push(a[i]);
            i--, j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else j--;
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
