#include <stdio.h>
#include <stdlib.h>


int euclid(int A,int B)
{
 if (B==0) return A;
 else return euclid(B,A%B);
}



int main()
{
 int x,y;
 int n;
 FILE *f;
 FILE *g;

 f=fopen("euclid2.in","r");
 g=fopen("euclid2.out","w");

 fscanf(f,"%d",&n);

 while (n)
 {
  fscanf(f,"%d %d",&x,&y);
  fprintf(g,"%d\n",euclid(x,y));
  n--;
 }

 fclose(g);
  return 0;
}
