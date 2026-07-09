#include <stdio.h>

int main(){
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	long T,a,b,r;
	scanf("%ld",&T);
	for(int i=0; i<T ; i++){
		scanf("%ld %ld",&a,&b);
		while( b ) {
		r = b;
		b = a % b;
		a = r;
		}
		printf("%ld\n",a);
	}
	

}
