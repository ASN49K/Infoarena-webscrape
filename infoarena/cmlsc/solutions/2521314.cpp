#include <bits/stdc++.h>
#define Dim 1025
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int dp[Dim][Dim],N,M,A[Dim],B[Dim],pozi,pozj,R,maxim,Afis[Dim],cnt;


int main()
{
    f>>N>>M;
    for(int i=1;i<=N;i++) f>>A[i];
    for(int j=1;j<=M;j++) f>>B[j];

    dp[0][0]=0;
    for(int i=1;i<=N;i++)
    for(int j=1;j<=M;j++)
    {
      if(A[i]==B[j]) dp[i][j]=dp[i-1][j-1]+1;
         else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

         if(dp[i][j]>maxim)
         {
             maxim=dp[i][j];
             pozi=i;
             pozj=j;
         }
    }

    g<<maxim<<'\n';

    R=dp[pozi][pozj];
    while( R )
    {
        if( A[pozi]==B[pozj] )
        {
            Afis[++cnt]=A[pozi];
            pozi--;
            pozj--;
            R--;
        }
        else
        if( dp[pozi][pozj-1] >= dp[pozi-1][pozj] )
        {
            pozj--;
            R=dp[pozi][pozj];
        }
        else
        {
            pozi--;
            R=dp[pozi][pozj];
        }

    }
    for(int i=cnt;i>=1;i--) g<<Afis[i]<<" ";


    return 0;
}
