#include <stdio.h>

int gcd(int a, int b){

    int r;
    while(b){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    FILE *f_in, *f_out;

    f_in = fopen("euclid2.in", "r");
    f_out = fopen("euclid2.out", "w");

    int a, b, t;
    fscanf(f_in, "%d", &t);

    while(t--){

        fscanf(f_in, "%d %d", &a, &b);
        fprintf(f_out, "%d\n", gcd(a, b));
    }

    fclose(f_in);
    fclose(f_out);
}
