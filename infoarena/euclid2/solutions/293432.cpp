#include<stdio.h>
long long n,a,b;
long long cmmdc(long long, long long);
int main(){
freopen("euclid2.in", "r",stdin);
freopen("euclid2.out", "w", stdout);
scanf("%D",&n);
for(long long i=1;i<=n;i++){scanf("%D %D", &a,&b);
			    printf("%D", cmmdc(a,b));}
return 0;}
long long cmmdc(long long a,long long b){if(b==0)return a;
					 return (b,a%b);}