# include <stdio.h>

int t,i;
long a,b,r;

int main() {

  FILE *f = fopen("euclid2.in","r");
  FILE *g = fopen("euclid2.out","w");

  fscanf(f,"%d",&t);

  for (i=1;i<=t;i++) {
    fscanf(f,"%ld%ld",&a,&b);
    while (b!=0) {
      r=a%b;
      a=b;
      b=r;
    }
    fprintf(g,"%ld",a);
  }

  fclose(f);
  fclose(g);

  return 0;
}