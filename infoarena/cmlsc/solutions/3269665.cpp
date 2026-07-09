#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n,a[1030],b[1030],dp[1030][1030];
char pred[1030][1030];

void Afis()
{
    int x,y,afis[1030],k=0;
    x=n;
    y=m;
    while(x>0&&y>0)
    {
        if(pred[x][y]=='d')
            {
                afis[++k]=a[x];
                x--;
                y--;
            }
        else if(pred[x][y]=='v')
            y--;
        else x--;
    }
    while(k)
    {
        fout<<afis[k]<<" ";
        k--;
    }
}

int main()
{
    int i,j;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=n;i++)
        fin>>b[i];
    a[0]=-20;
    b[0]=-12;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    pred[i][j]='d';
                }
            else
                {
                    if(dp[i-1][j]>dp[i][j-1])
                    { dp[i][j]=dp[i-1][j]; pred[i][j]='n';}
                    else { dp[i][j]=dp[i][j-1]; pred[i][j]='v';}
                }
    fout<<dp[n][m]<<"\n";
    Afis();
    return 0;
}
