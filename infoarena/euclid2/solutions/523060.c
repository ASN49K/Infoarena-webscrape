/**
 * 000 Algoritmul lui Euclid
 * -------------------------
 * Mihai Cirlanaru
*/

#include <stdio.h>

int gcd (int a, int b) {
  int r;
  
  while ((r = a%b)) {
    a = b;
    b = r;
  }
  
  return b;
}

int main() {
  int n, a, b, c;
  FILE *f, *g;
  
  f = fopen("euclid2.in", "r");
  g = fopen("euclid2.out", "w");
  
  /* Read number of pairs */
  fscanf(f, "%d", &n);
  
  while (n--) {
    /* Read current pair */
    fscanf(f, "%d %d", &a, &b);
    c = gcd(a, b);
    
    fprintf(g, "%d\n", c);
  }

  fclose(f);
  fclose(g);
  return 0;
}