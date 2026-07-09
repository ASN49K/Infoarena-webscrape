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
    for(int i = 1; i <= M;i++)
        for(int j =1; j <= N; j++)
        {
            if(y[i] == x[j])
            {
                mat[i][j]++;
                sol[k++] = y[i];
            }
            mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
        }

}

void afis()
{
    printf("%d\n",k);
    for(int i = 0 ; i < k;i++)
    {
        printf("%d ", sol[i]);
    }
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    citire();
    LCS();
    afis();
    return 0;
}
