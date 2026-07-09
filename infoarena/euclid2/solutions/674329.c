#include<stdio.h>


int cmmdc(int a, int b) {
    if (a==0)
        return b;
    if (b==0)
        return a;

    while(a!=b) {
        if(a>b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }

    return a;
}


int main() {
    int **a;
    int t, i, c;

    FILE* in;
    in = fopen("euclid2.in", "r");

    FILE* out;
    out = fopen ("euclid2.out", "w");

    if(in == NULL) {
        printf("Nu a fost gasit fisierul de intrare!");
        fclose(in);
        return;
    }

    fscanf(in, "%d", t);
    for (i=0; i<*t; i++) {
        fscanf(in, "%d%d", &a[i][0], &a[i][1]);
        c = cmmdc(a[i][0], a[i][1]);
        fprintf(out, "%d \n", c);
    }

    fclose(in);
    fclose(out);

    return 0;
}
