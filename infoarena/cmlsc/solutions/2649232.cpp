#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1025][1025];
int a[1025] ,b[1025];
vector <int> sol;
int main() {
    int m, n;
    fin >> m >> n;
    for(int i = 1;i <= m; ++i)
        fin >> a[i];
    for(int i = 1;i <= n; ++i)
        fin >> b[i];
    for(int i = 1;i <= m; ++i)
        for(int j = 1;j <= n; ++j)
            if(a[i] == b[j]) {
                dp[i][j] = 1+ dp[i-1][j-1];
            }
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) ;

    fout << dp[m][n] <<"\n";
    int i=m;int j=n;
    while(i && j)
    {   if(a[i] == b[j])
        {   sol.push_back(a[i]);
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    for(int i = sol.size() - 1;i >= 0;i--)
        fout << sol[i] << " ";
    return 0;
}
