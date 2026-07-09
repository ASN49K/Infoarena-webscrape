#include<stdio.h>

int main()

{

 freopen("euclid2.in","r",stdin);
 freopen("euclid2.out","w",stdout);

 int i,n,a,b,r;
 scanf("%d",&n);

 for(i=1;i<=n;i++)

 {

  scanf("%d%d",&a,&b);

  while(b!=0)
  {
  r = a%b;
  a = b;
  b = r;
  }
  printf("%d",a);
 }

 fcloseall();

 return 0;
}
