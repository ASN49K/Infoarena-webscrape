#include<cstdio>
int main ()
{freopen ("nim.in","r",stdin);
freopen ("nim.out","w",stdout);
int m,n,i,j,x,k;
scanf("%d",&m);
for(i=1;i<=m;i++)
    {scanf("%d",&n);
    x=0;
    for(j=1;j<=n;j++)
        {scanf("%d",&k);
        x=x^k;
        }
    if(x==0)
        printf("NU\n");
    else
        printf("DA\n");
    }
return 0;
}
