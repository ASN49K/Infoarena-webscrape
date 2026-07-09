#include <cstdio>
#include <algorithm>
#include <vector>

#define Nmax 1100

using namespace std;
int N,M,DP[Nmax][Nmax],A[Nmax],B[Nmax];

void Read( void )
{
    scanf("%d%d",&N,&M);
    for(int i = 1; i <= N; ++i)
        scanf("%d",&A[i]);
    for(int i = 1; i <= M; ++i)
        scanf("%d",&B[i]);
}


void Solve()
{
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            if(A[i] == B[j])
                DP[i][j] = DP[i-1][j-1] + 1;
            else
                DP[i][j] = max(DP[i-1][j],max(DP[i-1][j-1],DP[i][j-1]));
    printf("%d\n",DP[N][M]);
}

vector<int> sol;

void Reconst()
{
    int i = N, j = M;
    while(i >= 1 && j >= 1)
    {
        if(A[i] == B[j])
        {
            sol.push_back(A[i]);
            --i;
            --j;
            continue;
        }
        if(DP[i-1][j] > DP[i][j-1])
            --i;
        else
            --j;
    }
    for(int i = DP[N][M] - 1; i >= 0; --i)
        printf("%d ",sol[i]);
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    Read();
    Solve();
    Reconst();

    return 0;
}
