#include <cstdio>
#define max(a,b) ((a)>(b) ?(a):(b))
#define MAXN 1030
int d[MAXN][MAXN], a[MAXN], b[MAXN], n, m;
void citire()
{
    int i;
    scanf("%d%d", &m, &n);
    for(i=1;i<=m;++i)
        scanf("%d", &a[i]);
    for(i=1;i<=n;++i)
        scanf("%d", &b[i]);
}
void dinamica()
{
    int i, j;
    for(i=1;i<=m;++i)
        for(j=1;j<=n;++j)
        {
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j], d[i][j-1]);
        }
}
void afisare()
{
    int bst=0;
    int i=m, j=n, sir[MAXN];
    while(i&&j)
    {
        if(a[i]==b[j])
        {
            sir[++bst]=a[i];
            --i;
            --j;
        }
        else
            if(d[i-1][j]>d[i][j-1])
                --i;
            else
                --j;
    }
    printf("%d\n", bst);
    for(i=bst;i>=1;--i)
        printf("%d ", sir[i]);
    printf("\n");
}
void rezolva_problema()
{
    citire();
    dinamica();
    afisare();
}
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    rezolva_problema();
    return 0;
}
