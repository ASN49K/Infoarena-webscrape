#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, v1[260], v2[260], sir[260];
int dp[260][260];
void ciitre()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>v1[i];
    for(int j=1;j<=m;j++)
        fin>>v2[j];
}
void programaredinamica()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(v1[i]==v2[j])
            dp[i][j]=1+dp[i-1][j-1];
        else
            dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    }
    fout<<dp[n][m]<<'\n';
}
void drum()
{
int    cnt=0, i,j;
    for( i=n, j=m; i; )
    {
        if(v1[i]==v2[j])
                sir[++cnt]=v1[i], i--, j--;
        else
            if(dp[i-1][j]<dp[i][j-1])
            j--;
        else
            i--;
    }
    for(int k=cnt;k>=1;k--)
        fout<<sir[k]<<" ";

}
int main()
{
    ciitre();
    programaredinamica();
    drum();
}
