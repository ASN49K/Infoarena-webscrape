#include <cstdio>
#include <algorithm>
#define n 1025
using namespace std;

int mat[n][n];
int N,M;
int x[n];
int y[n];
int sol[n];
void citire()
{
    scanf("%d %d",&N,&M);
    for(int i = 1 ; i <=N;i++)
    {
        scanf("%d",&x[i]);
    }
    for(int j = 1 ; j <=M;j++)
    {
        scanf("%d",&y[j]);
    }
}
int k;
void LCS()
{
    int maxMat = 0;
    for(int i = 1; i <= M;i++)
        for(int j =1; j <= N; j++)
        {
            if(y[i] == x[j])
            {
                mat[i][j] = max(mat[i-1][j],mat[i][j-1]) + 1;

            }
            mat[i][j] = max(mat[i][j],max(mat[i-1][j],mat[i][j-1]));
        }

}

void afis()
{
    printf("%d",mat[M][N]);

    for(int i = M; i > 0;)
    {
        for(int j = N ; j >0;)
        {
            if(mat[i][j] == mat[i][j-1])
            {
                j--;
            }
            else
            if(mat[i][j] == mat[i-1][j])
            {
                i--;
            }
            else
            {
                sol[k++] = x[i];
                j--;
            }
        }
    }
    for(int i = 0; i < k;i++)
    {
        printf("%d ",sol[i]);
    }
}



void debug()
{
    for(int i = 0 ; i <= M;i++)
    {
        for(int j = 0 ; j  <= N ; j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    //freopen("cmlsc.out","w",stdout);
    citire();
    LCS();
    debug();
    afis();
    return 0;
}
