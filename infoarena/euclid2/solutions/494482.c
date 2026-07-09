#include <stdio.h>

FILE *in; FILE *out;
long a,b,i;

int main () {
    in=fopen ("euclid2.in","r"); out=fopen ("euclid2.out","w");
    fscanf (in,"%ld%ld",&a,&b);
    while (b) {
          i=a%b;
          a=b;
          b=i;
    }
    fprintf (out,"%ld\n",a);
    fclose (in); fclose (out);
    return 0;
}
