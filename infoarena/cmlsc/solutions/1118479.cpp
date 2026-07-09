#include<cstdio>
int a[1050],b[1050],v[1050],n,m;
int cmlsc(int x,int y)
{
    if(x==0||y==0) return 0;
    if(a[x]==b[y]) {v[x]=1;return cmlsc(x-1,y-1)+1;}
    int g,h;
    g=cmlsc(x-1,y);
    h=cmlsc(x,y-1);
    if(g>=h)return g;
    return h;
}
int main()
{
    int i;
    freopen("cmlsc.in","rt",stdin);
    freopen("cmlsc.out","wt",stdout);
    scanf("%ld%ld",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%ld",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%ld",&b[i]);
    printf("%ld\n",cmlsc(n,m));
    for(i=1;i<=n;i++)
        if(v[i]==1)printf("%ld ",a[i]);
}
