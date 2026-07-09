#include <cstdio>

int cmmdc ( int a, int b ) {
	if (b == 0) return a;
	return cmmdc(b,a%b);
}

int main() {
	freopen("euclid2.in","rt",stdin);
	freopen("euclid2.out","wt",stdout);
	int a = 0,b = 0,t = 0;
	for (scanf("%d",&t); t; --t) {
		scanf("%d %d",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}
	return 0;
}
