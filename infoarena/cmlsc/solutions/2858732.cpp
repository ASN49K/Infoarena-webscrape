#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[1030], b[1030], dp[1030][1030];

void citire()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>a[i];
    for(int i=1; i<=m; i++)
        fin>>b[i];
}

int maxim(int a, int b, int c)
{
    if(a>=b && a>=c)
        return a;
    else if(b>=a && b>=c)
        return b;
    return c;
}

void subsir()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=maxim(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
    fout<<dp[n][m]<<"\n";
}

void afisare(int i, int j)
{
    if(dp[i][j]==0)
        return;
    if(a[i]==b[j])
    {
        afisare(i-1, j-1);
        fout<<a[i]<<" ";
    }
    else if(maxim(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])==dp[i-1][j-1])
        afisare(i-1, j-1);
    else if(maxim(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])==dp[i-1][j])
        afisare(i-1, j);
    else
        afisare(i, j-1);
}

int main()
{
    citire();
    subsir();
    afisare(n, m);
    return 0;
}
