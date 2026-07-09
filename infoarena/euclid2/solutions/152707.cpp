#include<stdio.h>
long a,b;
int main()
{
 freopen("euclid2.in","r",stdin);
 freopen("euclid2.out","w",stdout);
 scanf("%ld %ld",&a,&b);
 while(a!=b)if(a>b)a=a-b;
			else b=b-a;
 if(a!=1)printf("%ld",a);
  else printf("0");
 fclose(stdout);
 return 0;
}