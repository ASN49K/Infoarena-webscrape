#include <stdio.h>

int main(){
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	long T,a,b,r;
	scanf("%ld",&T);
	while(T--){
		scanf("%ld %ld",&a,&b);
		while( b ) {
		r = b;
		b = a % b;
		a = r;
		}
		printf("%ld\n",a);
	}
	

}
