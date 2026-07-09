#include <stdio.h>

long long cmmdc(long long a,long long b){
long long c;
	while(b!= 0){
		c = a %b;
		a = b;
		b = c;

	}

	return a;

}


int main(){
int i,n;
long long x,y;
	freopen("euclid2.in","r",stdin);
	scanf("%d",&n);
	freopen("euclid2.out","w",stdout);
	for (i=0;i<n;i++){
		scanf("%lld %lld",&x,&y);
		printf("%lld\n",cmmdc(x,y));

	}
	
	fclose(stdin);
	fclose(stdout);






	return 0;
}
