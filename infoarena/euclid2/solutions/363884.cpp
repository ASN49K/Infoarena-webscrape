#include <stdio.h>

int main(){
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int a,b,n,r;
	scanf("%u",&n);
	while(n>0){
		n--;
		scanf("%u %u",&a,&b);
		while(b>0){
			r=a%b;
			a=b;
			b=r;
		}
		printf("%u\n",a);
	}

	return 0;
}