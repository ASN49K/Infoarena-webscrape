#include<stdio.h>
#include<algorithm>
using namespace std;

int n,a[1026][1026],x[1026],y[1026],i,j,k,m,sol[1026];

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d %d",&n,&m);
    for (i=1; i<=n ; ++i) scanf("%d",&x[i]);
    for (i=1; i<=m ; ++i) scanf("%d",&y[i]);
    for (i=1; i<=n; ++i)
            for (j=1; j<=m ; ++j)
                if (x[i]==y[j]) a[i][j]=a[i-1][j-1]+1;
                        else a[i][j]=max(a[i-1][j],a[i][j-1]);
    int sol1=a[n][m];
    printf("%d\n",sol1);
    while (n&&m)
    {
        if (x[n]==y[m])
        {
        sol[a[n][m]]=x[n];
        --m;
        --n;
        }
        else
            if (a[n][m-1]>a[n-1][m]) --m;   else --n;
    }
    for (i=1; i<=sol1; ++i)
        printf("%d ",sol[i]);
    return 0;
}
