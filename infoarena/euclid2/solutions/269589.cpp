#include <stdio.h>
int n;
int main()
{
 int i, x, y;
 FILE *fi=fopen("euclid2.in", "r"), *fo=fopen("euclid2.out", "w");
 fscanf(fi, "%d", &n);
 for(i=1; i<=n; i++)
  {
   fscanf(fi, "%d%d", &x, &y);
   while(x!=y)
   {
    if(x<y) y-=x;
     else x-=y;
    }
   fprintf(fo, "%d\n", x);
  }
 fclose(fi);
 fclose(fo);
 return 0;
}