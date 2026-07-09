#include <stdio.h>
#include <stdlib.h>

// https://infoarena.ro/problema/euclid2

#define INPUT_FILE "euclid2.in"
#define OUTPUT_FILE "euclid2.out"

int main() {
    unsigned int a = 0, b = 0;
    unsigned int t = 0;
    FILE *in = NULL, *out = NULL;
    if((in = fopen(INPUT_FILE, "r")) == NULL) {
        fprintf(stderr, "Eroare la deschidere fisier input\n");
        exit(-1);
    }
    if((out = fopen(OUTPUT_FILE, "w")) == NULL) {
        fprintf(stderr, "Eroare la deschidere fisier output\n");
        exit(-2);
    }

    fscanf(in, "%u", &t);
    
    while(t--) {
        fscanf(in, "%u %u", &a, &b);
        while(a != 0 && b != 0) {
            if(a >= b) a = a % b;
            else b = b % a;
        }
        fprintf(out, "%d\n", a == 0 ? b : a);
    }

    fclose(in);
    fclose(out);
    return 0;
}