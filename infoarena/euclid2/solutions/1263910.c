#include <stdio.h>
 FILE *f,*g;
int main() {
  int a,b,r;
 f=fopen("euclid2.in","r");
 g=fopen("euclid2.out","w");
  fscanf(f,"%d%d",&a,&b);
  while (b>0) {
    r=a%b;
    a=b;
    b=r;
  }
  fprintf(g,"%d\n",a);

  return 0;
}
