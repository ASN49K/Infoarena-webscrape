#include <stdio.h>
#define FIN "euclid2.in"
#define FOUT "euclid2.out"

// Funcția Euclid pentru cmmdc
int euclid(int a, int b) {
    int r = a % b;
    while (r) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main() {
    int a, b, T;
    FILE *fin = fopen(FIN, "r");
    FILE *fout = fopen(FOUT, "w");

    if (!fin || !fout) {
        printf("Eroare la deschiderea fisierelor.\n");
        return 1;
    }

    fscanf(fin, "%d", &T);  // citesc numarul de teste

    for (int i = 0; i < T; i++) {
        fscanf(fin, "%d %d", &a, &b);
        fprintf(fout, "%d\n", euclid(a, b));
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
