#include <stdio.h>
int main()
{int i,a,b,h,cmmdc;
freopen("cmmdc.in", "r",stdin);
freopen("cmmdc.out", "w",stdout);
scanf("%d%d",&a,&b); 
if(a<b) h=a; else h=b;
	for(i=1;i<=h;++i)
	if(a%i==0 && b%i==0) cmmdc=i; 
	if(cmmdc==1) printf("0");
	else printf("%d",cmmdc);
return 0;
}
	