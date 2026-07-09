#include <bits/stdc++.h>
std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");
int a[1025];
int b[1025];
int dp[1025][1025], n, m;
bool ap[257];
int sol[1025];
void afisare()
{
    for(int i = 1; i <= n; i++,fout <<'\n')
        for(int j = 1; j <= m ; j++)
            fout << dp[i][j] << ' ';
}
int main()
{
    int k = 0;
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
    }
    for(int j = 1; j <= m; j++){
        fin >> b[j];
    }
    int maxi = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] * (i - 1 >= 1) * (j - 1 >= 1) + 1;
            else
            dp[i][j] = std::max(dp[i - 1][j] * (i - 1 >= 1), dp[i][j - 1] * (i - 1 >= 1));
            
            if(dp[i][j] > maxi)
            {
                maxi = dp[i][j];
                sol[++k] = a[i];
            }
        }
    }
    fout << maxi << '\n';
    for(int i = 1; i <= k; i++)
        fout << sol[i] << ' ';
    //afisare();
    return 0;
}