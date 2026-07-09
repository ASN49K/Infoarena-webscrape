#include <bits/stdc++.h>

using namespace std;

const int arr_dim = 1028;

int N , M;
int A[arr_dim] , B[arr_dim];
int dp[arr_dim][arr_dim];

void Read()
{
    freopen("cmlsc.in", "r", stdin);
    scanf ("%d %d", &N , &M);
    for(int i = 1 ; i <= N ; ++i)
        scanf("%d", A + i);
    for(int i = 1 ; i <= M ; ++i)
        scanf("%d", B + i);
}

void afis(int x , int y , int l)
{
    if(l == 0) return;
   if(A[x] == B[y])
   {
       afis(x - 1 , y - 1 , l - 1);
       printf("%d ", A[x]);
       return;

   }
  if(dp[x - 1][y] > dp[x][y - 1])
        afis(x - 1 , y , l);
     else
           afis(x , y - 1 , l);

}

void Solve()
{
    for(int i = 1 ; i <= N ; ++i)
        for(int j = 1 ; j <= M ; ++j)
            if(A[i] == B[j])
               dp[i][j] = 1 + dp[i - 1][j - 1] ;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    freopen("cmlsc.out", "w", stdout);
    printf("%d\n", dp[N][M]);
    afis(N , M , dp[N][M]);
}

int main()
{
    Read();
    Solve();
    return 0;
}
