#include <stdio.h>
#include <stdlib.h>

int main(){
  FILE*fin=fopen("euclid2.in", "r");
  FILE*fout=fopen("euclid2.out", "w");
  int n, a, b, r, i;
  fscanf(fin, "%d", &n);
  for(i=1; i<=n; i++){
    fscanf(fin, "%d%d", &a, &b);
    r=0;
    while(b>0){
      r=a%b;
      a=b;
      b=r;
    }
    fprintf(fout, "%d\n", a);
  }
  fclose(fin);
  fclose(fout);
  return 0;
}
