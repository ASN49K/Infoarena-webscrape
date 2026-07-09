#include<stdio.h>

int n,v1[100001],v2[100001];
int r,i,j;

int main()

{

freopen ("euclid2.in","r",stdin);
freopen ("euclid2.out","w",stdout);

scanf ("%d",&n);

for (i=1;i<=n;i++)
    scanf ("%d%d",&v1[i],&v2[i]);

for (i=1;i<=n;i++)
    {
    while (v2[i])
        {
        r=v1[i]%v2[i];
        v1[i]=v2[i];
        v2[i]=r;
        }
    printf ("%d\n",v1[i]);
    }

return 0;
}
