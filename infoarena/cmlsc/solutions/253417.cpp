#include<stdio.h>
int v[1025],sir[1025],n,m,lg;
int main()
   {int i,x,min,max;
    freopen("cmlsc.in","r",stdin); freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&n,&m);
    scanf("%d",&x); v[x]=1; min=max=x;
    for(i=2;i<=n;i++)
       {scanf("%d",&x),v[x]=1;
        if(max<x) max=x;
        if(min>x) min=x;
       }
    for(i=1;i<=m;i++)
       {scanf("%d",&x),v[x]++;
        if(max<x) max=x;
        if(min>x) min=x;
       }
    for(i=min,lg=0;i<=max;i++)
       if(v[i]==2)
         sir[++lg]=i;
    printf("%d\n",lg);
    for(i=1;i<=lg;i++) printf("%d ",sir[i]);
    return 0;
}
