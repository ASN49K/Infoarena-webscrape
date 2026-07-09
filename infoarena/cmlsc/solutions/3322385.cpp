#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int dp[1030][1030];
int v[1030], a[1030];
int main()
{
    int n, m;
    fin >> m >> n;
    for(int i=1; i <= m; i++)
        fin >> a[i];
    for(int j=1; j <= n; j++)
        fin >> v[j];
    for(int i=1; i <= m; i++)
    {
        for(int j=1; j <= n; j++)
        {
            if(a[i]==v[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    fout << dp[m][n] << '\n';
    int i=m, j=n;
    vector<int> rez;
    while(i > 0 && j > 0)
    {
        if(a[i]==v[j])
        {
            rez.push_back(a[i]);
            i--;
            j--;
        }
        else if(dp[i-1][j] >= dp[i][j-1])
            i--;
        else
            j--;
    }
    reverse(rez.begin(), rez.end());
    for(auto I : rez)
        fout << I << " ";
    return 0;
}
