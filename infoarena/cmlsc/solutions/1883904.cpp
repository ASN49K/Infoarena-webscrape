#include <iostream>
#include <cstdio>
#define NMAX 1030
using namespace std;

int N,M;
int dp[NMAX][NMAX];
int A[NMAX],B[NMAX];

void citire()
{
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
        scanf("%d",&A[i]);
    for(int i=1;i<=M;i++)
        scanf("%d",&B[i]);
}

void rezolvare()
{
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            if(A[i]==B[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
}

void afisare(int i,int j)
{
    if(i==0)
    {
        printf("%d\n",dp[N][M]);
        return;
    }
    if(dp[i-1][j-1]+1==dp[i][j])
    {
        afisare(i-1,j-1);
        printf("%d ",A[i]);
    }
    else if(dp[i-1][j]==dp[i][j])
        afisare(i-1,j);
    else if(dp[i][j-1]==dp[i][j])
        afisare(i,j-1);

}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.in","r",stdin);

    citire();
    rezolvare();
    afisare(N,M);

    return 0;
}
