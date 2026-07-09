#include <stdio.h>
int n;
int main()
{
 int a, b, c;
 FILE *fi=fopen("euclid2.in", "r"), *f=fopen("euclid2.out", "w");;
 fscanf(fi, "%d", &n);
 for(; n; n--)
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
 fclose(fi);
 return 0;
}