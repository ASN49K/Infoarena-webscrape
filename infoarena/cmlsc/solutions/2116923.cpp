#include <bits/stdc++.h>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
const short Nmax = 1025;
int a[Nmax] , b[Nmax] , dp[Nmax][Nmax] , n , m;
/**
    dp[i][j] - > lungimea celui mai lung subsir comun din subsecventa a[1 .. i]
                 respectiv b[1 .. j]
    dp[i][j] = dp[i - 1][j - 1] + 1 <=> a[i] = b[j]
               max(dp[i - 1][j] , dp[i][j - 1])
    Sol : dp[n][m]
*/
void R(int i , int j)
{
    if(i < 1 || j < 1)
        return;
    if(a[i] == b[j])
    {
        R(i - 1 , j - 1);
        fout << a[i] << " ";
    }
    else if(dp[i][j - 1] > dp[i - 1][j])
        R(i , j - 1);
    else R(i - 1 , j);
}
int main()
{
    fin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        fin >> a[i];
    for(int i = 1 ; i <= m ; i++)
        fin >> b[i];
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
    else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
    fout << dp[n][m] << "\n";
    R(n , m);
    fout << "\n";
    fin.close();
    fout.close();
    return 0;
}
