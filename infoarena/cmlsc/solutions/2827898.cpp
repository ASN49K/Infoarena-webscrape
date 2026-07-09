#include <iostream>
#include<fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n , m, dp[1025][1025] , a[1025] , b[1025];
void sirul(int l , int c)
{
    if(l==0||c==0)
        return;
    if(a[l]==b[c])
    {
        sirul(l-1 , c-1);
        out<<a[l]<<" ";
    }
    else if(dp[l-1][c]>dp[l][c-1])
    {
        sirul(l-1 , c);
    }
    else sirul(l , c-1);
}
int main() {
    in>>m>>n;
    for(int i=1;i<=m;i++)
        in>>a[i];
    for(int i=1;i<=n;i++)
        in>>b[i];
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            if(a[i]!=b[j])
                dp[i][j]=max(dp[i][j-1] , dp[i-1][j]);
        }
    }
    out<<dp[m][n]<<'\n';
    sirul(m , n);
    return 0;
}
