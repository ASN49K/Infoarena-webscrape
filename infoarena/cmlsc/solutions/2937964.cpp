#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMAX=1029;
int dp[NMAX][NMAX];
int a[NMAX];
int b[NMAX];

void refac_subsir(int l,int c)
{
    if(l==0 || c==0)
        return ;
    if(a[l]==b[c])
    {
        refac_subsir(l-1,c-1);
        fout<<a[l]<<" ";
    }
    else if(dp[l][c-1]>dp[l-1][c])
        refac_subsir(l,c-1);
    else
        refac_subsir(l-1,c);
}

int main()
{
    int n,m,i,j;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    fout<<dp[n][m]<<"\n";
    refac_subsir(n,m);
    return 0;
}
