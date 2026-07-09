#include<cstdio>
using namespace std;
long long a,b,c;
long long CMMDC( long long n, long long m){
	int rest;
	while(m){
		rest=n%m;
		n=m;
		m=rest;
	}
return n;
}

int main(){
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %lld",&a,&b);
		c=CMMDC(a,b);
		printf("%lld\n",c);
	}
	return 0;
}

