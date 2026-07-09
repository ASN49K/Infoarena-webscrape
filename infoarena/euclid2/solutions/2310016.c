#include <stdio.h>

int euclid(int a, int b) {
  if(!a || !b) return a + b;
  
  if(a > b)
    return euclid(a % b, b);
  return euclid(a, b % a);
}

int main() {
  FILE *input, *output;
  int pairsNb, pairA, pairB;

  input = fopen("euclid.in", "r");
  output = fopen("euclid.out", "w");

  fscanf(input, "%d", &pairsNb);

  for(;pairsNb > 0; pairsNb--) {
    fscanf(input, "%d %d", &pairA, &pairB);
    fprintf(output, "%d\n", euclid(pairA, pairB));
  }

  fclose(input);
  fclose(output);
  
  return 0;
} 
