#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;


#define nmax 1030

int N, M, A[nmax], B[nmax], C[nmax][nmax];
vector<int> V;

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int i, j;
    scanf("%i %i", &N, &M);
    for(i = 1; i <= N; i++) scanf("%i", &A[i]);
    for(i = 1; i <= M; i++) scanf("%i", &B[i]);
    for(i = 1; i <= N; i++)
          for(j = 1; j <= M; j++)
                if(A[i] == B[j])
                        C[i][j] = C[i - 1][j - 1] + 1;
                else   
                       C[i][j] = max(C[i - 1][j], C[i][j - 1]);
    printf("%i\n", C[N][M]);
    int ll = N, cc = M;
    while(ll && cc)
    {
             if(ll && cc && A[ll] == B[cc])
             {
                   V.push_back(A[ll]);
                   ll --;
                   cc --;
             }
             if(ll && C[ll][cc] == C[ll - 1][cc]) ll --;
             if(cc && C[ll][cc] == C[ll][cc - 1]) cc --;
    }
    vector<int> :: reverse_iterator it;
    for(it = V.rbegin(); it != V.rend(); ++it) printf("%i ", *it);
    return 0;
}
    
