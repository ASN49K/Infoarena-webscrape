#include <bits/stdc++.h>
#define Dim 1030
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int N,M,A[Dim],B[Dim],dp[Dim][Dim];
int write[Dim],cnt,a,b;

int main()
{
    f>>N>>M;
    for(int i=1;i<=N;i++) f>>A[i];
    for(int j=1;j<=M;j++) f>>B[j];

    dp[0][0]=0;

    for(int i=1;i<=N;i++)
    for(int j=1;j<=M;j++)
    if(A[i]==B[j]) dp[i][j]=dp[i-1][j-1]+1;
    else
    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

    g<<dp[N][M]<<'\n';
    a=N,b=M;

    while(a>0&&b>0)
    {
        if(A[a]==B[b])
        {
            write[++cnt]=A[a];
            a--;
            b--;
        }
        else
        if(dp[a][b]==dp[a-1][b]) a--;
        else
        if(dp[a][b]==dp[a][b-1]) b--;
    }
    for(int i=cnt;i>=1;i--) g<<write[i]<<" ";

    return 0;
}
