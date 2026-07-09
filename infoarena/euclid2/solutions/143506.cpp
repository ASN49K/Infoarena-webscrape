#include <stdio.h>

unsigned long int a;
unsigned long int b;
unsigned long int r;

int main(){


  FILE *f = fopen("euclid2.in","r");
  fscanf(f,"%ld%ld",&a, &b);

  fclose(f);

  while (b!=0) {
    r=a%b;
    a=b;
    b=r;
  }


  FILE *g = fopen("euclid2.out","w");
  fprintf(g,"%ld\n",a);
  fclose(g);

  return 0;
}