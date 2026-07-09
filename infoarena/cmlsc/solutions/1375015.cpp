# include <cstdio>
# define N 1030
# include <algorithm>
# define f first
# define s second

using namespace std;

int i,j,a[N],b[N],n,m;
int sol[N];
int d[N][N];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d\n", &n, &m);
    for(i=1; i<=n; ++i)
        scanf("%d", &a[i]);
    for(i=1; i<=m; ++i)
        scanf("%d", &b[i]);

    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);

    printf("%d\n", d[n][m]);


    i--;j--;

    while(sol[0]<d[n][m])
    {
        if(a[i]==b[j]) sol[++sol[0]]=a[i];
        else if(d[i-1][j]>d[i][j-1]) j++;
        else i++;
        i--; j--;
    }

    for(i=sol[0]; i>=1; --i)
        printf("%d ", sol[i]);


}
