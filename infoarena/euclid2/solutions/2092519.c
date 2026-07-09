#include <stdio.h>


int main() {
  FILE *fin=fopen("euclid2.in","r");
  FILE *fout=fopen("euclid2.out","w");
  int n,i,r,a,b;

  fscanf(fin,"%d",&n);
  r=1;
  for(i=0;i<n;i++) {
    fscanf(fin,"%d%d",&a,&b);
    while(b>0) {
      r=a%b;
      a=b;
      b=r;
    }
    fprintf(fout,"%d\n",a);
  }
  fclose(fin);
  fclose(fout);
  return 0;
}
