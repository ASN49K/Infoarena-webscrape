#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <stack>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    int n, m;
    fin >> n >> m;
    int a[n + 1], b[m + 1];
    for (int i = 1; i <= n; ++i)
    {
        fin >> a[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        fin >> b[i];
    }
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i] == b[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    fout << dp[n][m] << "\n";
    stack<int> st;
    int i = n;
    int j = m;
    int currSize = dp[n][m];

    while (i > 0 && j > 0)
    {
        if (currSize == dp[i - 1][j - 1] + 1 && a[i] == b[j])
        {
            st.push(a[i]);
            --i;
            --j;
            --currSize;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                --j;
            }
            else
            {
                --i;
            }
        }
    }
    while (!st.empty())
    {
        fout << st.top() << " ";
        st.pop();
    }

    return 0;
}