#include <stdio.h>

int euclid(int a, int b) {
  if(!a) return b;
  if(!b) return a;
  
  if(a >= b)
    return euclid(a % b, b);
  return euclid(a, b % a);
}

int main() {
  FILE *input, *output;
  int pairsNb, pairA, pairB;

  input = fopen("euclid.in", "r");
  output = fopen("euclid.out", "w");

  fscanf(input, "%d", &pairsNb);

  int index;
  for(index = 0; index < pairsNb; index++) {
    fscanf(input, "%d %d", &pairA, &pairB);
    fprintf(output, "%d\n", euclid(pairA, pairB));
  }

  fclose(input);
  fclose(output);
  
  return 0;
} 
