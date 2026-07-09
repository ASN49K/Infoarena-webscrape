#include <bits/stdc++.h>

FILE *in = fopen("euclid2.in", "r"), *out = fopen("euclid2.out", "w") ;

int main() {
        long long a, b ;
        int test ;
        fscanf(in, "%d", &test) ;
        for (int i = 1 ; i <= test ; ++ i) {
                fscanf(in, "%d %d", &a, &b) ;
                fprintf(out, "%d\n", std::__gcd(a, b)) ;
        }
}
