#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m;
int a[1030], b[1030], fri[1030], frj[1030];
int dp[1030][1030];
vector <int> sol;
int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i ++)
        fin >> a[i];
    
    for(int j = 1; j <= m; j ++)
        fin >>b[j];

    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            if(a[i] == b[j])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                if(fri[i] == 0 && frj[j] == 0)
                    sol.push_back(a[i]);
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    fout << dp[n][m] << "\n";
    for(auto it: sol)
        fout << it << " ";
    return 0;
}