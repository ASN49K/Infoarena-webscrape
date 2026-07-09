#include <stdio.h>
int main () {
 int n, i, a, b, c;
 FILE *in,*out;
in = fopen("euclid2.in", "rt");
    out = fopen("euclid2.out", "w+");
 
  fscanf (in, "%d", &n);
 for (i = 0; i < n; i++) {
     fscanf (in, "%d %d", &a, &b);
            while (a != b)
            {
                  if (a > b)
                  {
                     c = a-b;
                     a = b;
                     b = c;
                  }
            else
            {
                b = b-a;
            }
  
            }
                fprintf(out,"%d\n", b);
                }
  
fclose(in);
fclose(out);
  
return 0;
  
}
