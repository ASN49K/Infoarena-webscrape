#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int nMax = 1030;
const int mMax = 1030;

int dp[nMax][mMax];
int a[nMax];
int b[mMax];
int n, m;
int sol[nMax];
int rasp = 0;

void citire()
{
    in >> m >> n;
    for(int i = 1; i <= m; ++i)
        in >> a[i];
    for(int i = 1; i <= n; ++i)
        in >> b[i];
}

void rezolvare()
{
    dp[0][0] = 0;
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
        {
            if(a[i] == b[j])
            {
                dp[i][j] = dp[i-1][j-1] + 1;

            }
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
}

void afisare()
{
    out << dp[m][n] << "\n";
    for(int i = m, j = n; i > 0;)
    {
        if(a[i] == b[j])
        {
            sol[++rasp] = a[i];
            --i;
            --j;
        }
        else if(dp[i-1][j] < dp[i][j-1])
            --j;
        else
            --i;
    }

    for(int i = rasp; i > 0; --i)
        out << sol[i] << " ";
}

int main()
{
    citire();
    rezolvare();
    afisare();
    return 0;
}
