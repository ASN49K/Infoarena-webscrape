#include <iostream>
#include <cstdio>


#define NMAX (1024+11)

using namespace std;

int M, N, A[NMAX], B[NMAX], v[NMAX], dp[NMAX][NMAX], tmp;

int main() {

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &M, &N);

    for(int i=1; i<= M; ++i)
    {
        scanf("%d", &A[i]);

    }
    for(int i=1; i<= N; ++i)
    {
        scanf("%d", &B[i]);
    }

    for(int i=1; i<=M; ++i)
    {
        for(int j=1; j<=N; ++j)
        {

            if(A[i] == B[j])
            {
            dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

            }


        }
    }
    for(int i=M, j=N; i>0 ;)
    {
        if(A[i] == B[j])
        {
            v[++tmp] = A[i];
            --i;
            --j;
        }
        else if(dp[i][j-1] > dp[i-1][j])
        --j;
        else
        --i;
    }

   printf("%d\n", tmp);

   for(int i=tmp; i>0; --i)
   {
       printf("%d ", v[i]);
   }

    return 0;
}
