#include <fstream.h>

long t,i;
long long a, b;

long long cmmdc(long long x, long long y){
	if (x%y==0)
		return y;
	else
		return cmmdc(y, x%y);
}

main(){
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	scanf("%ld", &t);
	for(i=1;i<=t;i++){
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", cmmdc(a, b));}
}
	