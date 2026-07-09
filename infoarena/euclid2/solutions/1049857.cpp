#include <stdio.h>
using namespace std;

long long euclid(long long a, long long b){
	if(b == 0)
		return a;
	else
		return euclid(b, a%b);
}

int main(){
	int T,i;
	long long a,b;

	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	
	scanf("%d",&T);
	for(i=1; i<=T; i++){
		scanf("%lld %lld",&a,&b);
		printf("%lld\n",euclid(a,b));
	}
	return 0;
}
