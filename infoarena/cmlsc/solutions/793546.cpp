#include <cstdio>

#define N 1025
#define max(a, b) ((a > b) ? a : b)

int m, n, a[N], b[N], c[N][N], sir[N],nr;

void citire()
{
    scanf("%d %d", &m, &n);
    for(int i=1;i<=m;i++)
        scanf("%d ", &a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d ", &b[i]);
}

void prelucrare()
{
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            if(a[i] == b[j])
                c[i][j] = 1 + c[i-1][j-1];
            else
                c[i][j] = max(c[i-1][j], c[i][j-1]);
    int i = m;
    int j = n;

    while(i)
    {
        if(a[i] == b[j])
        {
            sir[++nr] = a[i], --i, --j;
        }
        else if(c[i-1][j] < c[i][j-1])
            --j;
        else
            --i;
    }

   printf("%d\n", nr);
   for (int i = nr; i>0; i--)
        printf("%d ", sir[i]);
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    citire();
    prelucrare();
    return 0;
}
