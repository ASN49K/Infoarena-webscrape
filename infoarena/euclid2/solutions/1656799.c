#include<stdio.h>
#include<stdlib.h>

int cmmdc(int a, int b) {
  if (b==0) return a;
  return cmmdc(b, a%b);
}

int main(void) {
  FILE *f, *g;
  f = fopen("euclid2.in", "r");
  g = fopen("euclid2.out", "w");
  int p, a, b, m;
  fscanf(f, "%d\n", &p);
  while(p--) {
     fscanf(f, "%d %d", &a, &b);
     fprintf(g, "%d\n", cmmdc(a,b));
  }
  return 0;
}
