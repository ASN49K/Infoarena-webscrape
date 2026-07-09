#include <stdio.h>
int main()
{ long a,b,t,i,r;
  freopen("euclid2.in","rt",stdin);
  freopen("euclid2.out","wt",stdout);
  scanf("%ld",&t);
  for (i=1;i<=t;i++)
	{ scanf("%ld %ld",&a,&b);
	  r=1;
	  while (r)
		{ r=a%b;
		  a=b;
		  b=r;
		}
	  printf("%ld\n",a);
	}
  return 0;
}
