#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a, int b) {
int r;
    do {
       r = a % b;
       a = b;
       b = r;
    } while (r != 0);
    return a;
}

int main() {
FILE *f, *g;
int n, i, x, y;

     f = fopen("euclid2.in", "rt");
     g = fopen("euclid2.out", "wt");
     
     fscanf(f, "%i", &n);
     for (i = 1; i <= n; i++) {
         fscanf(f, "%i%i", &x, &y);
         fprintf(g, "%i\n", cmmdc(x,y));
     }

     fclose(f);
     fclose(g);
return 0;
}
