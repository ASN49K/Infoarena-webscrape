#include <stdio.h>
int main()
{int d,i,r,n;

 freopen("euclid2.in","r",stdin);
 freopen("euclid2.out","w",stdout);
 
 scanf("%d",&n);
 for (;n;--n)
 {
 
 scanf("%d %d",&d,&i);
 
 for (;;)
 if (!i) { printf("%d\n",d); break;} else {r=d;d=i;i=r%i;}
 }
return 0;}