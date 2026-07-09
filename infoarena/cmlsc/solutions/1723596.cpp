#include <cstdio>
#include <algorithm>

using namespace std;

const int Nmax = 2005;
int DP[Nmax][Nmax],N,M;
int A[Nmax],B[Nmax],sol[Nmax];

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d%d", &N, &M);
    for(int i = 1; i <= N; ++i)
        scanf("%d", &A[i]);
    for(int i = 1; i <= M; ++i)
        scanf("%d", &B[i]);

    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            if(A[i] == B[j])
                DP[i][j] = DP[i-1][j-1] + 1;
            else
                DP[i][j] = std::max(DP[i-1][j],std:: max( DP[i-1][j-1], DP[i][j-1]));

    printf("%d\n", DP[N][M]);


    int i = N, j = M,best = DP[N][M];
    while(i >= 1 && j >= 1)
    {
        if(A[i] == B[j])
        {
            sol[best--] = A[i];
            --i;
            --j;
            continue;
        }
        if(DP[i-1][j] > DP[i][j-1])
            --i;
        else
            --j;
    }
    for(int i = 1; i <= DP[N][M]; ++i)
        printf("%d ",sol[i]);
    return 0;
}
