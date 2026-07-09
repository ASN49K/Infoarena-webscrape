#include<stdio.h>
long a,b,x,t,i,n;
long euclid(long x,long y){
	int r;
	while (r){
		r=x%y;
		x=y;
		y=r;
	}
	return(x);
}

int main(){
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%ld",&n);
	for (i=1; i<=n; i++){
		scanf("%ld %ld",&a,&b);
		t=euclid(a,b);
		printf("%ld\n",t);
	}
	return(0);
}
