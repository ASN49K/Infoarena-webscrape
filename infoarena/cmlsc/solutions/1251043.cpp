# include <cstdio>
# include <algorithm>
# define N (1<<10)

using namespace std;

int n,m;
int d[N][N];
int a[N],b[N],sol[N];
int i,j;

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d\n", &n, &m);
    for(i=1; i<=n; ++i)
        scanf("%d", a+i);
    for(i=1; i<=m; ++i)
        scanf("%d", b+i);

    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            if(a[i]==b[j]) d[i][j]=1+d[i-1][j-1];
            else d[i][j]=max(d[i][j-1],d[i-1][j]);

    i--; j--;
    while(sol[0]<d[n][m])
    {
        if(a[i]==b[j])
        {
            sol[++sol[0]]=a[i];
            i--;
            j--;
        }
        else if(d[i-1][j]>d[i][j-1]) i--;
        else j--;
    }

    printf("%d\n", d[n][m]);
    for(i=sol[0]; i>=1; --i)
        printf("%d ", sol[i]);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
