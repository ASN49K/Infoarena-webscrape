#include <stdio.h>
#include <stdlib.h>

int main(){
  long long n, a, b, r;
  FILE *fin, *fout;
  fin=fopen("euclid2.in", "r");
  fout=fopen("euclid2.out", "w");
  fscanf(fin, "%lld", &n);
  while(n--){
    fscanf(fin, "%lld%lld", &a, &b);
    while(b){
      r=a%b;
      a=b;
      b=r;
    }
    fprintf(fout, "%lld", a);
  }
  fclose(fin);
  fclose(fout);
    return 0;
}
