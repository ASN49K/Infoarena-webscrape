#include <stdio.h>
#include <stdlib.h>

long euclid(long a,long b) {
	if (b==0) return a;
	return euclid (b,a%b);
}

int main() {
	long t,x,y,i;
	freopen ("euclid2.in","r",stdin);
	freopen ("euclid2.out","w",stdout);
	
	scanf ("%ld",&t);
	for (i=1; i<=t;i++) {
		scanf ("%ld %ld",&x,&y);
		printf ("%ld \n",euclid(x,y));
	}


	return 0;
}