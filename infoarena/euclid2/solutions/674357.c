#include<stdio.h>
#include<stdlib.h>

int cmmdc(int a, int b) {
    if (a==0)
        return b;
    if (b==0)
        return a;
    int t;

    while(b!=0) {
        t = b;
        b = a%b;
        a = t;
    }

    return a;
}

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}


int main() {
    int a,b;
    int t, i, c;

    FILE* in = fopen("euclid2.in", "r");
    FILE* out = fopen ("euclid2.out", "w");

    fscanf(in, "%d", &t);

    for (i=0; i<t; i++) {
        fscanf(in, "%d %d", &a, &b);
        fprintf(out, "%d \n", gcd(a, b));
    }

    fclose(in);
    fclose(out);

    return 0;
}
