#include <iostream>
#include <cstdio>
#define NMAX 1025
using namespace std;

int N,M;
int a[NMAX],b[NMAX];
int dp[NMAX][NMAX];
void citire()
{
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=M;i++)
        scanf("%d",&b[i]);
}

void rezolvare()
{
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

}

void reconstituie(int i,int j)
{
    if(dp[i][j] == 0) return;
    if(dp[i][j] == dp[i-1][j-1]+1)
    {
        reconstituie(i-1,j-1);
        printf("%d ",a[i]);
    }
    else if(dp[i][j] == dp[i-1][j])
    {
        reconstituie(i-1,j);
    }
    else
        reconstituie(i,j-1);

}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    citire();
    rezolvare();
    cout<<dp[N][M]<<endl;
    reconstituie(N,M);
    return 0;
}
