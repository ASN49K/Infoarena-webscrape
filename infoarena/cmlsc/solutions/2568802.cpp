#include <iostream>
#include <fstream>
#include <vector>
#define NMAX 1024

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, a[NMAX+10], b[NMAX+10], dp[NMAX+10][NMAX+10];
vector <int> sol;

int main()
{
    f >> n >> m;
    for(int i=1; i<=n; i++) f >> a[i];
    for(int i=1; i<=m; i++) f >> b[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            {   if(a[i] == b[j]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
    g << dp[n][m] << '\n';
    int i=n, j=m;
    while(i && j)
        {   if(a[i] == b[j]) sol.push_back(a[i]), i--, j--;
            else
                {   if(dp[i-1][j] > dp[i][j-1]) i--;
                    else j--;
                }
        }
    for(int i=sol.size()-1; i>=0; i--) g << sol[i] << ' ';
    g << '\n';
    return 0;
}
