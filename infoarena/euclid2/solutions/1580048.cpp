#include<stdio.h>

int T,a,b;

int euclid(int a,int b){
	if(!b)
		return a;

	return euclid(b,a%b);
}

int main(){

	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);

	scanf("%u",&T);

	for(;T>0;T--){
		scanf("%u %u",&a,&b);

		printf("%u\n",euclid(a,b));
		
}

return 0;

}