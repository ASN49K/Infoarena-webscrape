# include <cstdio>
# include <algorithm>
# define N 1050

using namespace std;

int a[N],b[N],d[N][N],sol[N];
int n,m;

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d\n", &n, &m);
    for(int i=1; i<=n; ++i)
        scanf("%d", &a[i]);
    for(int i=1; i<=m; ++i)
        scanf("%d", &b[i]);

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);

    printf("%d\n", d[n][m]);

    int i=n; int j=m;

    while(i!=0 && j!=0)
    {
        if(a[i]==b[j]) sol[++sol[0]]=a[i],i--,j--;
        else if(d[i-1][j]>=d[i][j-1]) i--;
        else j--;
    }

    for(int i=sol[0]; i>=1; --i)
        printf("%d ", sol[i]);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
