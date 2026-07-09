#include <stdio.h>

int main(){
  FILE *in = fopen("nim.in", "r");
  FILE *out = fopen("nim.out", "w");
  int t, n, i, x, j, y;
  fscanf(in, "%d", &t);
  for(i = 0; i < t; i++){
    fscanf(in, "%d", &n);
    x = 0;
    for(j = 0; j < n; j++){
      fscanf(in, "%d", &y);
      x ^= y;
    }
    if(x == 0)  fprintf(out, "NU\n");
    else        fprintf(out, "DA\n");
  }
  fclose(in);
  fclose(out);
  return 0;
}
