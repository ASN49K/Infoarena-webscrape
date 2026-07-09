#include <iostream>
#include <cstdio>

using namespace std;

const int NMax = 1030;
int a[NMax], b[NMax];
int dp[NMax][NMax];
int N, M;

void Drum(int i, int j)
{
    if(i==0 || j==0)
        return;

    if(a[i]==b[j])
    {
        Drum(i-1,j-1);
        printf("%d ", a[i]);
    }

    else
        if(dp[i-1][j] > dp[i][j-1])
            Drum(i-1,j);

    else
        Drum(i,j-1);
}


int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &N, &M);

    for(int i=1; i<=N; ++i)
        scanf("%d", &a[i]);

    for(int i=1; i<=M; ++i)
        scanf("%d", &b[i]);

    for(int i=1; i<=N; ++i)
        for(int j=1; j<=M; ++j)
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    int i = N, j = M;

    printf("%d\n", dp[N][M]);

    Drum(N, M);

    return 0;
}
