#include<cstdio>
int main()
{ freopen("euclid2.in","r",stdin);
  freopen("euclid2.out","w",stdout);
  int t,i,a,b,r;
  scanf("%d",&t);
  for(i=1;i<=t;i++)
  { scanf("%d%d",&a,&b);
    while(b)
    { r=a&b;
      a=b;
      b=r;
    }
    printf("%d\n",a);
  }
  return 0;
}
