#include <stdio.h>
int n,m,x[1024],y[1024],res[1024],p;

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
     for(int i=0;i<m;i++)
    {
        scanf("%d",&y[i]);
    }

     for(int i=0;i<n;i++)
    {
         for(int j=0;j<m;j++)
        {
           if(x[i]==y[j])
           {
               res[p]=x[i];p++;
           }
        }
    }
    printf("%d\n",p);
    for(int i=0;i<p;i++)
    {
        printf("%d ",res[i]);
    }
return 0;
}
