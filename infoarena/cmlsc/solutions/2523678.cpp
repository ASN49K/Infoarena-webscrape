#include <iostream>
#include <fstream>
#define Nmax  1030
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");


int n, m;
int nsol;
int a[Nmax];
int b[Nmax];
int v[Nmax];
int dp[Nmax][Nmax];

void Read()
{
    int i;
    fin>>n>>m;
    for(i=1;i<=n;++i)fin>>a[i];
    for(i=1;i<=m;++i)fin>>b[i];
}

void Print()
{
    int i=n,j=m;
    while(i>0&&j>0)
    {
        if(a[i]==b[j])
        {
            v[++nsol]=a[i];
            i--;j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])i--;
            else j--;
    }
    for(i=nsol;i>=1;--i)fout<<v[i]<<" ";

}

void Solve()
{
    int i,j;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    fout<<dp[n][m]<<"\n";
    Print();
}
int main()
{
    Read();
    Solve();
    return 0;
}
