#include <iostream>
#include <cstdio>
using namespace std;
int f[1030],g[1030],h[1030][1030],h1[1030],k,i,m,x,j;
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&x,&m);
    for(k=1;k<=x;k++)
        scanf("%d",&f[k]);
    for(k=1;k<=m;k++)
        scanf("%d",&g[k]);
    for(k=1;k<=x;k++)
    {
        for(i=1;i<=m;i++)
        {
            if(f[k]==g[i])
                h[k][i]=h[k-1][i-1]+1;
            else
                h[k][i]=max(h[k-1][i],h[k][i-1]);
        }
    }
    for(k=x,i=m,j=1;k>=1&&i>=1;)
    {
        if(f[k]==g[i])
        {
            h1[j]=f[k];
            j++;
            k--;
            i--;
        }
        else
        {
            if(h[k-1][i]>h[k][i-1])
                k--;
            else
                i--;
        }
    }
    printf("%d\n",j-1);
    for(k=j-1;k>=1;k--)
        printf("%d ",h1[k]);
    return 0;
}
