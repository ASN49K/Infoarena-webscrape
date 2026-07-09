#include <stdio.h>
#include <stdlib.h>

#define IN "euclid2.in"
#define OUT "euclid2.out"

inline void swap (int *a, int *b){
    int c;
    c = a;
    a = b;
    b = c;
}

int euclid (int a, int b){
    int r = a % b;

    if (a < b)
        swap (&a, &b);

    while (r){
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

int main(){
    FILE *fin, *fout;
    fin = fopen (IN, "r");
    fout = fopen (OUT, "w");

    int t, a, b;
    fscanf (fin, "%d", &t);

    while (t) {
        fscanf (fin, "%d%d", &a, &b);
        fprintf (fout, "%d\n", euclid(a, b));

        --t;
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
