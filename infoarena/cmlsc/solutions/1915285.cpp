#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int NMax = 1100;

int v1[NMax], v2[NMax];
int dp[NMax][NMax];
int N1, N2;

void Read()
{
    scanf("%d%d", &N1, &N2);

    for(int i=1; i<=N1; ++i)
        scanf("%d", &v1[i]);

    for(int i=1; i<=N2; ++i)
        scanf("%d", &v2[i]);

}

int ind=0;
int sol[NMax];

void CMLSC()
{
    for(int i=1; i<=N1; ++i)
        for(int j=1; j<=N2; ++j)
            if(v1[i]==v2[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);

    for(int i=N1, j=N2; i; )
    {
        if(v1[i]==v2[j])
        {
            sol[++ind]=v1[i];
            --i;
            --j;
        }

        else if(dp[i-1][j] < dp[i][j-1])
            --j;

        else
            --i;
    }

    printf("%d\n", ind);

    for(int i=ind; i; --i)
        printf("%d ", sol[i]);
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    Read();
    CMLSC();

    return 0;
}
