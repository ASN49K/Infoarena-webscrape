#include<stdio.h>
int a,b;
int i,t;

int cmmdc (int a, int b){
  if (b==0) return a;
  return cmmdc (b,a%b);
}

int main () {
  FILE *f = fopen("euclid2.in", "r");
  FILE *g = fopen("euclid2.out", "w");
  fscanf(f,"%d",&t);
  for (i=0;i<t;i++){
    fscanf(f,"%d %d",&a, &b);
    fprintf(g,"%d\n",cmmdc (a,b));
  }
  fclose(f);
  fclose(g);
  return 0;
}

