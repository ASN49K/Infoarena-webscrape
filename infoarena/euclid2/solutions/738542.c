#include <stdio.h>
long cmmdc (long a, long b){
long c;
	while (b){
	c = a % b;
	a = b;
	b = c;


	}

	return a;
	
}



int main () {
int n,i;
long a,b;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&n);
	for(i = 0 ; i < n ; i++){
		scanf("%ld%ld",&a,&b);
		printf("%ld\n",cmmdc(a,b));
		
	}

	fclose(stdin);
	fclose(stdout);





	return 0;
}
