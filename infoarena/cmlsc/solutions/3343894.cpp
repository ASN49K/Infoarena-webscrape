#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, dp[1030][1030], a[1030], b[1030];

int main()
{
    fin>>n>>m;
    for(int i = 1; i <= n; ++i)
        fin>>a[i];
    for(int j = 1; j <= m; ++j)
        fin>>b[j];

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    fout<<dp[n][m]<<"\n";

    int i = n, j = m;
    stack<int> s;
    while(i >= 1 && j >= 1)
    {
        if(a[i] == b[j])
        {
            s.push(a[i]);
            --i;
            --j;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            --i;
        else
            --j;
    }
    while(!s.empty())
    {
        fout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}
