#include <bits/stdc++.h>

using namespace std;
int n,m,a[1030],b[1030],dp[1030][1030];
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
void Citire()
{
    int i;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    fin.close();
}

inline void Reconst(int i,int j)
{
    if(i==0||j==0) return;
    if(a[i]==b[j])
    {
        Reconst(i-1,j-1);
        fout<<a[i]<<" ";
    }
    else
    {
        if(dp[i-1][j]>dp[i][j-1])
            Reconst(i-1,j);
        else
            Reconst(i,j-1);
    }
}

void Rez()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
        else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    }
    fout<<dp[n][m]<<"\n";
    Reconst(n,m);

}


int main()
{
    Citire();
    Rez();
    return 0;
}
