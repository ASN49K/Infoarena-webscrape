#include <stdio.h>

int main(){
  FILE *in, *out;
  int t, n, i, rez, a;

  in = fopen("nim.in", "r");
  out = fopen("nim.out", "w");

  fscanf(in, "%d", &t);
  for(; t > 0; t--){
    fscanf(in, "%d%d", &n, &rez);

    for(i = 1; i < n; i++){
      fscanf(in, "%d", &a);
      rez = rez ^ a;
    }

    if(rez > 0)
      fprintf(out, "DA\n");
    else
      fprintf(out, "NU\n");
  }

  fclose(in);
  fclose(out);

  return 0;
}

/*
2
4
1 3 5 7
3
4 8 17
*/
