#include<stdio.h>
long long n,a[1000000000],b[1000000000];
long long cmmdc(long long a,long long b){
	int r=a%b;
	while (r){
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
int main(){
	int i;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%lld",&n);
	for (i=1;i<=n;++i)
		scanf("%lld%lld",&a[i],&b[i]);
	for (i=1;i<=n;++i)
		printf("%lld ",cmmdc(a[i],b[i]));
	return 0;
}
		
