#include<cstdio>
#include<algorithm>
using namespace std;
const int NMAX = 1050;
int i,j,N,M,A[NMAX],B[NMAX],DP[NMAX][NMAX],SOL[NMAX],Best;
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&N,&M);
    for(i=1;i<=N;i++) scanf("%d",&A[i]);
    for(i=1;i<=M;i++) scanf("%d",&B[i]);
    for(i=1;i<=N;i++)
        for(j=1;j<=M;j++)
            if(A[i]==B[j]) DP[i][j]=DP[i-1][j-1]+1;
            else DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
    Best=DP[N][M]; printf("%d\n",Best);
    for(i=N,j=M;Best;)
        if(A[i]==B[j]) SOL[Best--]=A[i],i--,j--;
        else if(DP[i][j]==DP[i-1][j]) i--;
        else j--;
    for(i=1,Best=DP[N][M];i<=Best;i++) printf("%d ",SOL[i]);
    return 0;
}