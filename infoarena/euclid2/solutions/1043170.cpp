# include <cstdio>

int gcd( int a, int b ) {
	int result ;
	/* Compute Greatest Common divisor using Euclid's Algorithm */
	__asm__ __volatile__ ( "movl %1, %%eax;"
						  "movl %2, %%ebx;"
						  "0: cmpl $0, %%ebx;"
						  "je 1f;"
						  "xorl %%edx, %%edx;"
						  "idivl %%ebx;"
						  "movl %%ebx, %%eax;"
						  "movl %%edx, %%ebx;"
						  "jmp 0b;"
						  "1: movl %%eax, %0;" : "=r" (result) : "r" (a), "r" (b)
	);

	return result ;
}

int main() {
    freopen ("euclid2.in", "r", stdin);
    freopen ("euclid2.out", "w", stdout);
    int T;
    for (scanf ("%d", &T); T; --T) {
        int first, second ;
        scanf( "%d%d", &first, &second );
        printf( "%d\n", gcd(first, second) ) ;
    }

	return 0 ;
}

