#include<cstdio>
#include<algorithm>

using namespace std;

const int NMAX = 1024+2;

int M,N,sol;
int A[NMAX],B[NMAX],V[NMAX];
int DP[NMAX][NMAX];

int main()
{
    int i,j;

    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d%d",&M,&N);

    for(i=1; i<=M; i++)
        scanf("%d",&A[i]);

    for(i=1; i<=N; i++)
        scanf("%d",&B[i]);

    for(i=1; i<=M; i++)
        for(j=1; j<=N; j++)
            if(A[i]==B[j]) DP[i][j]=DP[i-1][j-1]+1;
            else DP[i][j]=max(DP[i-1][j],DP[i][j-1]);

    i=sol=DP[M][N];

    printf("%d\n",sol);

    for(; DP[M][N];)
    {
        if(A[M]==B[N])
        {
            V[i--]=A[M];
            M--;
            N--;
            continue;
        }
        if(DP[M-1][N]<DP[M][N-1]) N--;
        else M--;
    }

    for(i=1; i<=sol; i++)
        printf("%d ",V[i]);

    return 0;
}
