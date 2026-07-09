#include <iostream>
#include <fstream>

long long cmmdc(long long a, long long b){
    long long c;
    while (b){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    FILE *in, *out;
    in = fopen("euclid2.in", "r");
    out = fopen("euclid2.out", "w");

    long long a, b, n;
    fscanf(in, "%lld", &n);

    for (int i = 0; i < n; i++){
        fscanf(in, "%lld %lld", &a, &b);
        fprintf(out, "%lld\n", cmmdc(a, b));
    }



    return 0;
}
