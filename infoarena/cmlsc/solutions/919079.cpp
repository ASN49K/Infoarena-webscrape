#include <cstdio>
#define max(a,b) ((a > b) ? a : b)
#define N 1030

using namespace std;

int mat[N][N], a[N], b[N], m, n;

void cauta()
{
    for(int i = 1; i <= m; i++)
        for(int j=1; j <= n; j++)
            if(a[i-1] == b[j-1])
                mat[i][j] = 1+mat[i-1][j-1];
            else
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
}

void drum(int i, int j)
{
    if(mat[i][j] == 0)
        return;
    if(a[i-1] == b[j-1])
    {
        drum(i-1, j-1);
        printf("%d ", a[i-1]);
        return;
    }
    if(mat[i-1][j] > mat[i][j-1])
    {
        drum(i-1,j);
        return;
    }
    drum(i,j-1);
}

void citire()
{
    scanf("%d %d",&m, &n);
    for(int i = 0; i < m; i++)
        scanf("%d ", &a[i]);
    for(int i = 0; i < n; i++)
        scanf("%d ", &b[i]);
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    citire();
    cauta();
    printf("%d\n",mat[m][n]);
    drum(m,n);
    return 0;
}
