#include <stdio.h>
int a,b,cmmdc;
int main()
{freopen("euclid2.in", "r", stdin);freopen("euclid2.out", "w", stdout);scanf("%d %d", &a, &b);cmmdc=b;if(b==0 ) cmmdc=a;else while(a%b!=0){cmmdc=a%b; a=b; b=cmmdc;} printf("%d\n", cmmdc); return 0;}
