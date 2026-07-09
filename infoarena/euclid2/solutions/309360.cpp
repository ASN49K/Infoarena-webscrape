#include <stdio.h>
int d,i,r,n;

int cmmdc(int a,int b)
{ 
	if (!b) return a;
    return cmmdc(b,a%b);
}	

int main()
{int d,i,r,n;

 freopen("cmmdc.in","r",stdin);
 freopen("cmmdc.out","w",stdout);
 
 scanf("%d",&n);
 for (;n;--n)
 {
 
 scanf("%d %d",&d,&i);
 printf("%d\n",cmmdc(d,i));

 }
return 0;}