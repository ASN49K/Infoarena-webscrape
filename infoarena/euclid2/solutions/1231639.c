#include <stdio.h>

/*
 * The routine finds the greatest common demominator of two numbers using Euclids 
 * algorithm.
 *
 * Arguments:
 *  a - First number.
 *  b - Second number.
 *
 * Returns: The GCD of a and b.
 */
int gcd_euclid(int a, int b) {
    int r;

    // Make a bigger than b.
    if (b > a) {
        b ^= a;
        a ^= b;
        b ^= a;
    }

    // Apply Euclid's algorithm,
    while (b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(void) {
    FILE* in = fopen("euclid2.in", "r");
    FILE* out = fopen("euclid2.out", "w");
    int count;
    fscanf(in, "%d", &count);
    while (count--) {
        int a, b;
        fscanf(in, "%d%d", &a, &b);
        int gcd = gcd_euclid(a, b);
        fprintf(out, "%d\n", gcd);
    }
    return 0;
}

