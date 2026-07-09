#include <stdio.h>
int main()
{int d,i,r,n;

 freopen("cmmdc.in","r",stdin);
 freopen("cmmdc.out","w",stdout);
 
 scanf("%d",&n);
 for (;n>0;n--)
 {
 
 scanf("%d %d",&d,&i);
 
 for (;;)
 if (!i) { printf("%d\n",d); break;} else {r=d;d=i;i=r%i;}
 }
return 0;}