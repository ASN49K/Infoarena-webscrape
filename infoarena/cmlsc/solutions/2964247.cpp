#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int dp[1025][1025], a[1025], b[1025], m, n, sol[1025];

int main()
{
    in >> m >> n;
    for(int i=1; i<=m; i++)
        in>>a[i];
    for(int j=1; j<=n; j++)
        in>>b[j];
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(a[i]!=b[j])
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
        }
    }
    out<<dp[m][n]<<"\n";
    int cn=n;
    int cm=m;
    int k=0;
    while(dp[cm][cn]!=0)
    {
        //cout<<cn<<" "<<cm<<"\n";
        if(a[cm]==b[cn])
        {
            sol[k++]=b[cn];
            cn--;
            cm--;
        }
        else if(a[cm]!=b[cn] && dp[cm-1][cn]>dp[cm][cn-1])
            cm--;
        else
            cn--;
    }
    for(int i=k-1; i>=0; i--)
        out<<sol[i]<<" ";
    return 0;
}
