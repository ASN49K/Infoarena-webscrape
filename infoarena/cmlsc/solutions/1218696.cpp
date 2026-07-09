#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int A[1025],B[1025],N,M;
int DP[1025][1025];
vector<int> sol;

void read( void )
{
    scanf("%d%d",&N,&M);
    for(int i = 1; i <= N; ++i)
        scanf("%d", A + i);
    for(int i = 1; i <= M; ++i)
        scanf("%d", B + i);
}

void dynamic( void )
{
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            if(A[i] == B[j])
                DP[i][j] = DP[i-1][j-1] + 1;
            else
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
    printf("%d\n",DP[N][M]);
}

void reconst(int x,int y)
{
    while(x && y)
        if(A[x] == B[y])
        {
            sol.push_back(A[x]);
            --x;
            --y;
        }
        else
            if(DP[x-1][y] > DP[x][y-1])
                --x;
            else
                --y;
    for(int i = sol.size()-1; i >= 0; --i)
        printf("%d ",sol[i]);
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    read();
    dynamic();
    reconst(N,M);

    return 0;
}
