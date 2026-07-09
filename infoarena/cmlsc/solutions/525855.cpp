#include <stdio.h>
#include <algorithm>
using namespace std;
#define nmax 1030

int SOL[nmax][nmax];
int a[nmax], b[nmax];
int N, M;

void citire ()
{
    int i;
    freopen("cmlsc.in","r",stdin);
    scanf("%d%d", &N, &M);
    for (i = 1; i <= N; ++i) scanf("%d", &a[i]);
    for (i = 1; i <= M; ++i) scanf("%d", &b[i]);
}

void drum(int x,int y)
{
    if (!x || !y)
        return;
    if (a[x] == b[y])
    {
        drum(x-1,y-1);
        printf("%d ",a[x]);
        return;
    }
    if (SOL[x-1][y] < SOL[x][y-1])
        drum(x, y-1);
    else
        drum(x-1 ,y);
}

void solve ()
{
    int i ,j, maxim, x, y;
    maxim = 0;
    for (i = 1; i <= N; ++i)
        for (j = 1; j <= M; ++j)
        {
            if (a[i] == b[j])
                SOL[i][j] = SOL[i-1][j-1]+1;
            else
                SOL[i][j] = max (SOL[i-1][j], SOL[i][j-1]);
            if (SOL[i][j] > maxim)
            {
                maxim = SOL[i][j];
                x = i; y = j;
            }
        }
    freopen("cmlsc.out","w",stdout);
    printf ("%d\n", maxim);
    drum (x ,y);
}

int main ()
{
    citire ();
    solve ();
    return 0;
}
