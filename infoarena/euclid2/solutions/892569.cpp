#include<stdio.h>

int n,v1,v2;
int r,i,j;

int main()

{

freopen ("euclid2.in","r",stdin);
freopen ("euclid2.out","w",stdout);

scanf ("%d",&n);

for (i=1;i<=n;i++)
    {scanf ("%d%d",&v1,&v2);
    while (v2)
        {
        r=v1%v2;
        v1=v2;
        v2=r;
        }
    printf ("%d\n",v1);
    }

return 0;
}
