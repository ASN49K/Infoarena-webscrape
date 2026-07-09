#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int DIM = 1030;
int a[DIM], b[DIM], dp[DIM][DIM];

signed main()
{
    int n, m;
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    for(int j = 1; j <= m; j++)
        fin >> b[j];

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    fout << dp[n][m] << "\n";

    vector<int> ans;
    while(n != 0 && m != 0)
    {
        if(a[n] == b[m])
        {
            ans.push_back(a[n]);
            n--, m--;
        }
        else if(dp[n-1][m] > dp[n][m-1])
            n--;
        else
            m--;
    }
    for(vector<int>::reverse_iterator it = ans.rbegin(); it != ans.rend(); it++)
        fout << *it << " ";

    return 0;
}
