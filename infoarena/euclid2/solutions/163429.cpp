#include <cstdio>
long long rezolva(long long a,long long b){
	if (b==0)
		return a;
    else 
		return rezolva(b,a%b);
}
int main(){
	int t,i;
	long a,b;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	for (i=1;i<=t;++i){
		scanf("%ld%ld",&a,&b);
		printf("%lld\n",rezolva(a,b));
	}
	return 0;
}
