#include<stdio.h>
int a,b,n;

int euclid(int a, int b)
{
    if (!b)
	  return a;
     else
	euclid(b,a%b);

}

int main(void)
{
freopen("euclid2.in","r",stdin);
freopen ("euclid2.out","w",stdout);
scanf("%d",&n);
for(int i=1;i<=n;i++)
	{scanf("%d %d", &a, &b);
	printf("%d\n",euclid(a,b));
	}

return 0;
}