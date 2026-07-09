#include <stdio.h>
int n;
int main()
{
 int a, b, c;
 FILE *fi=fopen("euclid2.in", "r"), *f;
 fscanf(fi, "%d", &n);
 fclose(f);
 f=fopen("euclid2.out", "w");
 for(; n; --n)
 {
  fscanf(fi, "%d%d", &a, &b);
  while(b)
  {
   c=b;
   b=a%b;
   a=c;
  }
 fprintf(f, "%d\n", a);
 }
 fclose(f);
 return 0;
}