#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <deque>
using namespace std;


int A[1100], B[1100], C[1100][1100], N, M, ll, cc;
deque<int> D;

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int i, j;
    scanf("%i %i", &N, &M);
    for(i = 1; i <= N; i++) scanf("%i", &A[i]);
    for(i = 1; i <= M; i++) scanf("%i", &B[i]);
    for(i = 1; i <= N; i++)
    {
          for(j = 1; j <= M; j++)
          {
                if(A[i] == B[j]) C[i][j] = C[i - 1][j - 1] + 1;
                else C[i][j] = max(C[i - 1][j], C[i][j - 1]);
          }
    }
    ll = N, cc = M;
    while(ll && cc)
    {
             if(ll && cc && A[ll] == B[cc])
             {
                   D.push_front(A[ll]);
                   ll --;
                   cc --;
             }
             if(ll && C[ll][cc] == C[ll - 1][cc]) ll --;
             if(cc && C[ll][cc] == C[ll][cc - 1]) cc --;
    }
    printf("%i\n", C[N][M]);
    for(i = 0; i < D.size(); i++) printf("%i ", D[i]);
    return 0;
}
