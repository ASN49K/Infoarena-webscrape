#include<cstdio>
int a[1050],b[1050],d[1050][1050],n,m,sir[1050];
int main()
{
    int i,nr=0,j;
    freopen("cmlsc.in","rt",stdin);
    freopen("cmlsc.out","wt",stdout);
    scanf("%ld%ld",&n,&m);
    for(i=1; i<=n; i++)
        scanf("%ld",&a[i]);
    for(i=1; i<=m; i++)
        scanf("%ld",&b[i]);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=(d[i-1][j]>d[i][j-1])?(d[i-1][j]):(d[i][j-1]);
    for (i=n,j=m;i;)
        if (a[i] == b[j])
            sir[++nr]=a[i],--i,--j;
        else if (d[i-1][j]<d[i][j-1])
            --j;
        else
            --i;
    printf("%ld\n",nr);
    for(i=nr;i>=1;i--)
        printf("%ld ",sir[i]);
}
