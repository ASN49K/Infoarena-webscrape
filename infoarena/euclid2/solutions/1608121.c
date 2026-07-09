#include <stdio.h>
#include <stdlib.h>

int main(){
  int n, a, b, r;
  FILE *fin, *fout;
  fin=fopen("euclid2.in", "r");
  fout=fopen("euclid2.out", "w");
  fscanf(fin, "%d", &n);
  while(n--){
  fscanf(fin, "%d%d", &a, &b);
    while(b){
      r=a%b;
      a=b;
      b=r;
    }
    fprintf(fout, "%d", a);
  }
  fclose(fin);
  fclose(fout);
    return 0;
}
