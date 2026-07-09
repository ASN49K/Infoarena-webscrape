#include <iostream>
#include <fstream>
#include <vector>
#define nmax 1030
using namespace std;

int n, m;
int a[nmax], b[nmax];
int dp[nmax][nmax];
vector <int> sol;

void read()
{
    ifstream f("cmlsc.in");
    f >> n >> m;
    for(int i=1; i<=n; ++i)
        f >> a[i];
    for(int i=1; i<=m; ++i)
        f >> b[i];
    f.close();
}

void dinam()
{
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
}

void out()
{
    ofstream g("cmlsc.out");
    g << dp[n][m] << '\n';
    for(int i=n, j=m; dp[i][j]; )
    {
        if(a[i] == b[j]) {sol.push_back(a[i]); --i; --j;}
        else if(dp[i-1][j] >= dp[i][j-1]) --i;
        else --j;
    }
    for(int i=sol.size()-1; i>-1; --i)
        g << sol[i] << ' ';
    g.close();
}

int main()
{
    read();
    dinam();
    out();
    return 0;
}
