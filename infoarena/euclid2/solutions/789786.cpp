#include <stdio.h>

long cmmdc(long a,long b){return b==0?a:cmmdc(b,a%b);}

int main(){

	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int t;long a,b;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%ld",&a);scanf("%ld",&b);
		printf("%ld\n",cmmdc(a,b));
	}
	return 0;
}