#include<cstdio>
int a[1030],b[1030],m,n,d[1030][1030],v[1030];
int max(int x,int y)
{
    if (x<y)
        return y;
    return x;
}

void afis()
{
    printf("%d\n",d[m][n]);
    int maxx=d[m][n],i=m,j=n;
    while (maxx)
    {
        if (d[i-1][j]==maxx)
        {
            --i;
            continue;
        }
        if (d[i][j-1]==maxx)
        {
            --j;
            continue;
        }
        v[maxx]=a[i];
        --i,--j,--maxx;
    }
    for (int i=1;i<=d[m][n];++i)
        printf("%d ",v[i]);
    printf("\n");
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&m,&n);
    for (int i=1;i<=m;++i)
        scanf("%d",&a[i]);
    for (int j=1;j<=n;++j)
        scanf("%d",&b[j]);
    for (int i=1;i<=m;++i)
        for (int j=1;j<=n;++j)
            if (a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    afis();
    return 0;
}
