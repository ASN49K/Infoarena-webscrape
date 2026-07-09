#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 1030
#define M 1030

using namespace std;

int n,m,a[N],b[M],mat[N][M],lmax,x,y;

void recursiv(int x, int y)
{
    if(!mat[x][y])
    {
        return;
    }
    if(a[x] == b[y])
    {
        recursiv(x - 1,y - 1);
        printf("%d ",a[x]);
    }
    else
    {
        if(mat[x][y] == mat[x][y - 1])
        {
            recursiv(x,y - 1);
            return;
        }
        if(mat[x][y] == mat[x - 1][y])
        {
            recursiv(x - 1,y);
            return;
        }
    }
}

void prelucrare()
{
    for(int i = 1 ; i <= n ; ++i)
    {
        for(int j = 1 ; j <= m ; ++j)
        {
            if(a[i] == b[j])
            {
                mat[i][j] = mat[i - 1][j - 1] + 1;

                if(mat[i][j] > lmax)
                {
                    lmax = mat[i][j];
                    x = i;
                    y = j;
                }
            }
            else
            {
                mat[i][j] = max(mat[i - 1][j] , mat[i][j - 1]);
            }
        }
    }
}

void citire()
{
    scanf("%d %d\n",&n,&m);

    for(int i = 1 ; i <= n ; ++i)
    {
        scanf("%d ",&a[i]);
    }
    scanf("\n");

    for(int i = 1 ; i <= m ; ++i)
    {
        scanf("%d ",&b[i]);
    }

    prelucrare();

    printf("%d\n",lmax);

    recursiv(x,y);
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    citire();

    return 0;
}
