#include <iostream>

using namespace std;

int N, M, A[1100], B[1100], i, j, DP[1100][1100], prevX[1100][1100], prevY[1100][1100];

void printSolution(int x,int y)
{
    if(DP[x][y] == 0)
        return;
    printSolution(prevX[x][y], prevY[x][y]);
    if(DP[x][y] != DP[prevX[x][y]][prevY[x][y]])
        printf("%d ",A[x]);
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d", &N, &M);
    for(i = 1; i <= N; i++)
        scanf("%d", &A[i]);
    for(i = 1; i <= M; i++)
        scanf("%d", &B[i]);
    for(i = 1; i <= N; i++)
        for(j = 1; j <= M; j++)
        {
            if(DP[i-1][j] > DP[i][j-1])
            {
                DP[i][j] = DP[i - 1][j];
                prevX[i][j] = i - 1;
                prevY[i][j] = j;
            }
            else
            {
                DP[i][j] = DP[i][j - 1];
                prevX[i][j] = i;
                prevY[i][j] = j - 1;
            }
            if(A[i] == B[j])
            {
                DP[i][j] = DP[i - 1][j - 1] + 1;
                prevX[i][j] = i - 1;
                prevY[i][j] = j - 1;
            }
        }
    printf("%d\n",DP[N][M]);
    printSolution(N, M);
    return 0;
}
