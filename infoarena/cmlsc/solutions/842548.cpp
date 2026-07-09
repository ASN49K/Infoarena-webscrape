#include <cstdio>
#define max(a,b) a>b?a:b

int v1[1030],v2[1030];
int n,m;

int x[1030][1030];

int sol[1030];

void rec()
{
    int i=n,j=m;
    while(x[i][j]!=0)
    {
        if(x[i-1][j-1]==x[i][j])
        {
            i--;
            j--;
        }
        else if(x[i-1][j]==x[i][j])
            i--;
        else if(x[i][j-1]==x[i][j])
            j--;
        else
        {
            sol[++sol[0]]=v1[i];
            i--;
            j--;
        }
    }
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d%d",&n,&m);

    for(int i=1; i<=n; i++)
        scanf("%d",&v1[i]);

    for(int i=1; i<=m; i++)
        scanf("%d",&v2[i]);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(v1[i]==v2[j])
                x[i][j]=x[i-1][j-1]+1;
            else
                x[i][j]=max(x[i-1][j],x[i][j-1]);
        }

    printf("%d\n",x[n][m]);

    rec();

    for(int i=sol[0];i>=1;i--)
        printf("%d ",sol[i]);

    return 0;
}
