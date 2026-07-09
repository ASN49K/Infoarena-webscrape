#include <stdio.h>

int main() {
    FILE *intrare = fopen("euclid2.in", "r");
    FILE *iesire = fopen("euclid2.out", "w");
    if(intrare == NULL || iesire == NULL) {
        return 1;
    }
    int x ,n1, n2, r;
    fscanf(intrare, "%d", &x);
    for(int i = 1; i <= x; i++) {
        while(n2 != 0) {
            r = n1 % n2;
            n1 = n2;
            n2 = r;
        }
        fprintf(iesire, "%d\n", r);
    }
    fclose(intrare);
    fclose(iesire);
    return 0;
}