#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fin ,*fout;
    int a, b, r, n, i;
    fin=fopen("euclid2.in", "r");
    fscanf(fin, "%d", &n);
    fout=fopen("euclid2.out", "w");
    for(i=0; i<n; i++){
    fscanf(fin, "%d%d", &a, &b );
    while ( b > 0 ) {
        r = a % b;
        a = b;
        b = r;
    }
    fprintf(fout, "%d\n", a);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
