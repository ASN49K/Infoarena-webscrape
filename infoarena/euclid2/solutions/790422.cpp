#include "stdio.h"
int N,A,B;
int gcd(int a,int b){
	if (!b) return a;
	else return gcd(b,a%b);
}
int main(void){
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&N);
	for (int i=0;i<N;i++){
		scanf("%D%D",&A,&B);
		printf("%d\n",gcd(A,B));
	}
	return 0;
}