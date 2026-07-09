#include <cstdio>
#include <algorithm>

#define Nmax 1026

using namespace std;
int A[Nmax],B[Nmax],DP[Nmax][Nmax];
int N,M,ans[Nmax];

void read()
{
    scanf("%d%d",&N,&M);
    for(int i = 1; i <= N; ++i)scanf("%d",A+i);
    for(int i = 1; i <= M; ++i)scanf("%d",B+i);
}

void dynamic()
{
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            if(A[i] == B[j])
                DP[i][j] = DP[i-1][j-1] + 1;
            else
                DP[i][j] = max(DP[i-1][j],max(DP[i][j-1],DP[i-1][j-1]));
}

void reconst(int i,int j)
{
    printf("%d\n",DP[N][M]);
    do
    {
        if(A[i] == B[j])
        {
            ans[++ans[0]] = A[i];
            --i;
            --j;
        }
        else
            if(DP[i-1][j] > DP[i][j-1]) --i;
            else -- j;
    }while (i && j);
    for(int i = ans[0]; i >= 1; --i)
        printf("%d ",ans[i]);
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    read();
    dynamic();
    reconst(N,M);

    return 0;
}
