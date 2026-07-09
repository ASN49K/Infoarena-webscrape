#include <stdio.h>

int minim(int a, int b) {
    if (a>b)
        return b;
    else
        return a;
}

void cmmdc(int x, int y) {
    int i = minim(x,y);
    int dvc = 0;
    for(int idx=1; idx <= i ; idx++) {
        if (x%idx==0 && y%idx==0) {
            dvc = idx;
        }
    }
    printf("%d\n", dvc);
}

int euclid(int a, int b, FILE *f) {
    int t;
    while ( b != 0) {
        //t=147
        t = b;
        //42
        b = a % b;
        //147
        a = t;
    }
    fprintf(f, "%d\n", a);
}

int main() {
    int t,a,b;
    FILE *fisier = fopen("euclid2.in", "r");
    FILE *fisierW = fopen("euclid2.out", "w");
    fscanf(fisier, "%d", &t);
    for (int i=0; i < t; i++) {
        fscanf(fisier, "%d %d", &a, &b);
        euclid(a, b, fisierW);
    }
    fclose(fisier);
    fclose(fisierW);
}