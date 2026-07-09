#include<stdio.h>


int cmmdc(int a, int b) {
    if (a==0)
        return b;
    if (b==0)
        return a;
    int t;

    while(b!=0) {
        t = b;
        b = b%a;
        a = t;
    }

    return a;
}


int main() {
    int a,b;
    int t, i, c;

    FILE* in;
    in = fopen("euclid2.in", "r");

    FILE* out;
    out = fopen ("euclid2.out", "w");

    fscanf(in, "%d", &t);
    for (i=0; i<t; i++) {
        fscanf(in, "%d %d", &a, &b);
        c = cmmdc(a, b);
        fprintf(out, "%d \n", c);
    }

    fclose(in);
    fclose(out);

    return 0;
}
