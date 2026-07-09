#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

#define Nmax 1030

vector<int> Ans;
int N, M, A[Nmax], B[Nmax], Dp[Nmax][Nmax];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int i, j;
    scanf("%i %i", &N, &M);
    for(i = 1; i <= N; ++i) scanf("%i", &A[i]);
    for(i = 1; i <= M; ++i) scanf("%i", &B[i]);
    for(i = 1; i <= N; ++i)
        for(j = 1; j <= M; ++j)
            if(A[i] == B[j])
                Dp[i][j] = Dp[i - 1][j - 1] + 1;
            else
                Dp[i][j] = max(Dp[i - 1][j], Dp[i][j - 1]);
    printf("%i\n", Dp[N][M]);
    int Lin = N, Col = M;
    while(Lin && Col)
    {
        if(Lin && Col && A[Lin] == B[Col])
        {
            Ans.push_back(A[Lin]);
            Lin --;
            Col --;
        }
        if(Lin && Dp[Lin][Col] == Dp[Lin - 1][Col]) Lin --;
        if(Col && Dp[Lin][Col] == Dp[Lin][Col - 1]) Col --;
    }
    for(i = Ans.size() - 1; i >= 0; i--)
        printf("%i ", Ans[i]);
    return 0;
}
