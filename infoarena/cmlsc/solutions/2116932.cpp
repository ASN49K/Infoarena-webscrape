#include <bits/stdc++.h>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
const short Nmax = 1025;
int a[Nmax] , b[Nmax] , dp[Nmax][Nmax] , n , m , sol[Nmax * Nmax] , nsol;
/**
    dp[i][j] - > lungimea celui mai lung subsir comun din subsecventa a[1 .. i]
                 respectiv b[1 .. j]
    dp[i][j] = dp[i - 1][j - 1] + 1 <=> a[i] = b[j]
               max(dp[i - 1][j] , dp[i][j - 1])
    Sol : dp[n][m]
*/
int main()
{
    int mx , pi , pj , x , y;
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
    mx = dp[n][m];
    pi = n + 1;
    pj = m + 1;
    while(mx > 0)
    {
        bool ok = false;
        for(int i = pi - 1 ; i >= 1 && ok == false ; i--)
            for(int j = pj - 1 ; j >= 1 && ok == false ; j--)
                if(mx == dp[i][j] && a[i] == b[j])
        {
            ++nsol;
            sol[nsol] = a[i];
            ok = true;
            x = i;
            y = j;
        }
        mx--;
        pi = x;
        pj = y;
    }
    for(int i = nsol ; i >= 1 ; i--)
        fout << sol[i] << " ";
    fout << "\n";
    fin.close();
    fout.close();
    return 0;
}
