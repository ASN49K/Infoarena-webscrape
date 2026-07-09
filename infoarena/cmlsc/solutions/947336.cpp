# include <cstdio>
# define MAXN 1100
using namespace std;
int a[MAXN],b[MAXN],sol[MAXN],r[MAXN][MAXN];
int i,j,k,n,m;
int Max(int a, int b)
{
    if(a>b) return a;
    return b;
}
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(i=1; i<=m; ++i) scanf("%d", &b[i]);

    if(a[1]==b[1]) r[1][1]=1;
    else r[1][1]=0;

    for(i=2; i<=m; ++i)
    if(a[1]==b[i]) r[1][i]=1;
    else r[1][i]=r[1][i-1];

    for(i=2; i<=n; ++i)
    if(b[1]==a[i]) r[i][1]=1;
    else r[i][1]=r[i-1][1];

    for(i=2; i<=n; ++i)
        for(j=2; j<=m; ++j)
        if(a[i]==b[j]) r[i][j]=1+r[i-1][j-1];
        else r[i][j]=Max(r[i-1][j], r[i][j-1]);

    printf("%d\n", r[n][m]);
    while(i>=1 && j>=1)
    {
        if(a[i]==b[j])
        {
            sol[++k]=a[i];
            i--;
            j--;
        }
        else if(r[i-1][j]==r[i][j]) i--;
        else j--;
    }
    for(i=k; i>=2; --i) printf("%d ", sol[i]);

}
