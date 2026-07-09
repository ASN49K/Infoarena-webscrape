#include <bits/stdc++.h>
#define Dim 1025
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int dp[Dim][Dim],A[Dim],B[Dim],S[Dim],cnt,N,M;


int main()
{
    f>>N>>M;
    for(int i=1;i<=N;i++) f>>A[i];
    for(int i=1;i<=M;i++) f>>B[i];

    dp[0][0]=0;

    for(int i=1;i<=N;i++)
    for(int j=1;j<=M;j++)
    if( A[i] == B[j] ) dp[i][j]=dp[i-1][j-1]+1;
    else dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));

    g<<dp[N][M]<<'\n';

    int tA=N,tB=M;

    while( tA!=0 && tB !=0 )
    {
        if(A[tA]==B[tB])
        {
            S[++cnt]=A[tA];
            tA--;
            tB--;
        }
        else
        {
            if( dp[tA][tB-1] > dp[tA-1][tB] ) tB--;
            else tA--;
        }
    }
    for(int i=cnt;i>=1;i--) g<<S[i]<<' ';

    return 0;
}
