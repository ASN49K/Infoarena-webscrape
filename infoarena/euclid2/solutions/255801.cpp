#include <stdio.h>

int n,a,b;
int cmmdc(int a, int b) {
	if (b==0) return a;
	else return cmmdc (b,a%b);
}

int main (void) {
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&n);
	for(;n;n--) {
		scanf("%d %d",&a,&b);
		printf("%d \n",cmmdc(a,b));
	}
return 0;
}