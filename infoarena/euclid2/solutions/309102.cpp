#include <stdio.h>
int main()
{int d,i,r;

 freopen("cmmdc.in","r",stdin);
 freopen("cmmdc.out","w",stdout);
 scanf("%d %d",&d,&i);
 
 for (r=d%i;r;)
{ d=i;
  i=r;
  r=d%i;
  
 }
if (i==1) i=0; 
printf("%d",i);
return 0;}