#include<stdio.h>
int main()
{int a,b,cmmdc;
freopen("euclid2.in", "r",stdin);
freopen("euclid2.out", "w",stdout);
scanf("%d%d",&a,&b);

if(a<4 || b<4) {cmmdc=1; printf("1"); return 0;} 
if( a==0 ) {cmmdc=b; printf("%d",cmmdc); return 0;} 
    while( b!=0 )
      {if( a>b )
           a=a-b;
       else
           b=b-a;
	  }
     cmmdc=a;
	printf("%d", cmmdc);
	 return 0;
}	