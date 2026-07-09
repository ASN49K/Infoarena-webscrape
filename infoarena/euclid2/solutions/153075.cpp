#include<stdio.h>
long long a,b;
long long cmmdc(long long a,long long b){
	if(b==0) 
		return a;
	return cmmdc(b, a%b);
}
int main(){
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%lld %lld",&a,&b);
	printf("%lld\n",cmmdc(a, b));
	return 0;
}
