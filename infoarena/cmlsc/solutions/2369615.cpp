#include <iostream>
#include <fstream>
#include <vector>
#define Nmax 1030

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m;
int a[Nmax], b[Nmax];
int dp[Nmax][Nmax];
vector <int> sol;

int main()
{
    f >> n >> m;
    for (int i = 1; i <= n; i++) f >> a[i];
    for (int i = 1; i <= m; i++) f >> b[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if(a[i] == b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);

    g << dp[n][m] << '\n';
    int i = n, j=m;
    while(i >= 1 && j >= 1)
    {
        while(dp[i][j] == dp[i-1][j]) i--;
        while(dp[i][j] == dp[i][j-1]) j--;
        sol.push_back(a[i]);
        i--,j--;
    }
    for (int i = sol.size()-1; i >= 0; i--) g <<  sol[i] << " ";

    return 0;
}
