#include<stdio.h>
long n,a,b;
long cmmdc(long,long);
int main(){
freopen("euclid2.in", "r",stdin);
freopen("euclid2.out", "w", stdout);
scanf("%d",&n);
for(long i=1;i<=n;i++){scanf("%d %d", &a,&b);
			    printf("%d", cmmdc(a,b));}
return 0;}
long cmmdc(long a,long b){if(b==0)return a;
					 return (b,a%b);}