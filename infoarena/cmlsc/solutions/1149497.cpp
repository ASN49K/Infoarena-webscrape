#include <cstdio>

using namespace std;

int a[1030],b[1030],c[1030];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,m,i,j,nr=0,lim=1;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
        scanf("%d",a+i);
    for(i=1;i<=m;++i)
        scanf("%d",b+i);
    for(i=1;i<=n;++i)
        for(j=lim;j<=m;++j)
            if(a[i]==b[j])
            {
                nr++;
                c[nr]=a[i];
                lim=j+1;
            }
    printf("%d\n",nr);
    for(i=1;i<=nr;++i)
        printf("%d ",c[i]);
    return 0;
}
