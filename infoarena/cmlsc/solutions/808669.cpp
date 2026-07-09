#include<cstdio>
int a[1025],b[1025],d[1025][1025],v[1025];



int max(int a, int b)
{
    if(a>b)
        return a;
    return b;
}



int lcs(int x, int y)
{
    if(x==0||y==0)
        return 0;
    if(a[x]==b[y])
    {
        v[++v[0]]=a[x];
        return d[x-1][y-1]+1;
    }
    return max(d[x][y-1],d[x-1][y]);
}


int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(i=1;i<=m;++i)
        scanf("%d",&b[i]);
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            d[i][j]=lcs(i,j);
    printf("%d\n",d[n][m]);
    for(i=1;i<=d[n][m];++i)
        printf("%d ",v[i]);
    return 0;
}
