#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");

const int maxi = 1025;

int m, n, a[maxi], b[maxi];
int dp[maxi][maxi];

vector <int> sol;

void citire()
{
    in >> n >> m;
    for(int i = 1; i <= n; i++)
        in >> a[i];
    for(int i = 1; i <= m; i++)
        in >> b[i];
}

void dinamica()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
    {
        if(a[i] == b[j])
            dp[i][j] = dp[i -1][j - 1] + 1;
        else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
    out << dp[n][m] << "\n";
}

void parcurgere()
{
    int i = n, j = m;

    while(dp[i][j] != 0)
    {
        if(a[i] == b[j])
        {
            sol.push_back(a[i]);
            i--;
            j--;
        }
        else
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
    }
    for(int i = 0; i < sol.size(); i++)
        out << sol[i] << " ";
}

int main()
{
    citire();
    dinamica();
    parcurgere();
    return 0;
}
