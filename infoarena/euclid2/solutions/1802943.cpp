#include <stdio.h>

inline int cmmdc(int a, int b){
  int r;
  while(b>0){
    r=a%b;
    a=b;
    b=r;
  }
  return a;
}

int main()
{
  int n, i, x, y;
  FILE *fi=fopen("euclid2.in", "r"), *fo=fopen("euclid2.out", "w");
  fscanf(fi, "%d", &n);
  for(i=0;i<n;i++){
    fscanf(fi, "%d%d", &x, &y);
    fprintf(fo, "%d\n", cmmdc(x,y));
  }
  fclose(fi);
  fclose(fo);
  return 0;
}
