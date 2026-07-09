#include <fstream>
#define N 1025
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n, m, a[N], b[N], dp[N][N];

void citire()
{
    fin>>n>>m;
    for (int i=1; i<=n; ++i) fin>>a[i];
    for (int j=1; j<=m; ++j) fin>>b[j];
}

void pd()
{
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            if (a[i]==b[j]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
}

void sir()
{
    int nr, sol[N];
    nr=0;
    int i=n, j=m;
    while (i>0)
    {
        if (a[i]==b[j]) sol[++nr]=a[i], i--, j--;
        else if (dp[i-1][j]<dp[i][j-1]) j--;
             else i--;
    }
    fout<<nr<<'\n';
    for (int i=nr; i>=1; --i) fout<<sol[i]<<' ';
}

int main()
{
    citire();
    pd();
    sir();
    return 0;
}