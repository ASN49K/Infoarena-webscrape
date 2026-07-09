# include <cstdio>

int gcd( int a, int b ) {
	int result ;
	/* Compute Greatest Common divisor using Euclid's Algorithm */
	__asm__ __volatile__ ( "movl %1, %%eax;"
						  "movl %2, %%ebx;"
						  "CONTD: cmpl $0, %%ebx;"
						  "je DONE;"
						  "xorl %%edx, %%edx;"
						  "idivl %%ebx;"
						  "movl %%ebx, %%eax;"
						  "movl %%edx, %%ebx;"
						  "jmp CONTD;"
						  "DONE: movl %%eax, %0;" : "=g" (result) : "g" (a), "g" (b)
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

