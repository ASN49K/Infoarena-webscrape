#include <cstdio>
#include <cstdlib>
#include <deque>
#include <algorithm>
using namespace std;


int N, M, A[1025], B[1025], C[1025][1025];
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
    printf("%i\n", C[N][M]);
    int ll = N, cc = M;
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
    deque<int> :: iterator it;
    for(it = D.begin(); it != D.end(); ++ it) printf("%i ",  *it);
    scanf("%i", &i);
    return 0;
}
