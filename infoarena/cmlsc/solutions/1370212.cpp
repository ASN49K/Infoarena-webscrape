#include <cstdio>
#include <algorithm>

#define Nmax (10+(1<<10))

using namespace std;

int N , M , i , j;
int A[Nmax] , B[Nmax] , sol[Nmax] , D[Nmax][Nmax];

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d %d", &N, &M);

    for (i = 1; i <= N; ++i) scanf("%d", &A[i]);
    for (i = 1; i <= M; ++i) scanf("%d", &B[i]);

    for (i = 1; i <= N; ++i)
     for (j = 1; j <= M; ++j)
      D[i][j] = (A[i] == B[j]) ? (1 + D[i-1][j-1]) : (max(D[i-1][j] , D[i][j-1]));

    for (i = N , j = M; i && j; )
    (A[i] == B[j]) ? (sol[++sol[0]] = A[i], i-- , j--) : ((D[i-1][j] < D[i][j-1]) ? --j : --i);

    for (printf("%d\n", sol[0]); sol[0]; --sol[0]) printf("%d ", sol[sol[0]]);

    return 0;
}
