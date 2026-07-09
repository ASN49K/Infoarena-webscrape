#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

stack<int> st;

int a[1025], b[1025], dp[1025][1025];

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, i, j;
    fin>>n>>m;
    for (i=1;i<=n;++i)
        fin>>a[i];
    for (i=1;i<=m;++i)
        fin>>b[i];
    fin.close();
    for (i=1;i<=n;++i)
        for (j=1;j<=m;++j)
        {
            if (a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    fout<<dp[n][m]<<'\n';
    i=n, j=m;
    while (i && j)
    {
        if (a[i]==b[j])
        {
            st.push(a[i]);
            --i, --j;
        }
        else if (dp[i-1][j]>dp[i][j-1])
                --i;
            else
                --j;
    }
    while (!st.empty())
    {
        fout<<st.top()<<' ';
        st.pop();
    }
    fout.close();

    return 0;
}
