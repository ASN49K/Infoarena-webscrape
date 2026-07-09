#include <stdio.h>


long cmmdc(long a, long b) {
    while (b) {
          long r = a%b;
          a = b;
          b = r;      
    }
    return a;
}

int main() {
    freopen("euclid2.in", "r",stdin);
	freopen("euclid2.out", "w",stdout);
	long T;
    scanf("%ld", &T);
	for (long i = 0; i < T; i ++) {
		long a,b;    
		scanf("%ld %ld", &a, &b);
		printf("%ld\n", cmmdc(a,b));
	}
	
    
    
    fclose(stdin);
	fclose(stdout);

    return 0;
}
