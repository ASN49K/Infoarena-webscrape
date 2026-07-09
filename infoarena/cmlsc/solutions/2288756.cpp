#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int LIM = 1025;

int dp[LIM][LIM];
int n,m,a[LIM],b[LIM];

void citire()
{
    fin >> n >> m;
    for (int i=1;i<=n;i++)
        fin >> a[i];
    for (int j=1;j<=m;j++)
        fin >> b[j];
}

void rezolva()
{
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

        }
    }
    fout << dp[n][m] << "\n";
}

void reconstrituire(int n,int m)
{
    if (n>=1 && m>=1)
    {
        if (a[n] == b[m])
        {
            reconstrituire(n-1,m-1);
            fout << a[n] << " ";
        }
        else
        if (dp[n-1][m] > dp[n][m-1])
        {
            reconstrituire(n-1,m);
        }
        else reconstrituire(n,m-1);
    }
}

int main()
{
    citire();
    rezolva();
    reconstrituire(n,m);
    return 0;
}
