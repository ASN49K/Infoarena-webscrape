#include<stdio.h>
int n,m,i,v[1051],x[1051],t,j,max[1051];
int main ()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&v[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&x[i]);
    for(i=1;i<=n;i++)
    {
        t=0;
        for(j=1;j<=m;j++)
            if(v[i]==x[j])
            {
                max[j]+=1;
                t=1;
            }
            else
                max[j]+=t;
    }
    printf("%d\n",max[m]);
    for(i=1;i<=m;i++)
        if(max[i]>max[i-1])
            printf("%d ",x[i]);
    return 0;
}
