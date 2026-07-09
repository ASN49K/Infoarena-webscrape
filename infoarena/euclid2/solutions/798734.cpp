# include <stdio.h>
# include <iostream>


int cmmdc (int a, int b) {
    int r;
 while (b) {
       r = a%b;
       a = b; 
       b = r;
       }
 return a;
}


int main ()  {
 
 FILE *f, *g;
 int a, b, n, i;
 f = fopen ("euclid2.in","r");
 g = fopen ("euclid2.out","w");
 fscanf (f, "%d", &n);
 for (i = 0; i < n; i++) {
  fscanf(f,"%d %d", &a, &b);
 
        fprintf(g,"%d\n", cmmdc(a,b));
        }

 return 0;   
}
