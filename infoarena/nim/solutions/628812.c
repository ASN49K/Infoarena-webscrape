#include <stdio.h>

int main () {
    FILE * in=fopen ("nim.in","r");
    FILE * out=fopen ("nim.out","w");
    int k,s,t,i,n,j;
    fscanf (in,"%d",&t);
    for (i=0; i<t; i++) {
        fscanf (in,"%d",&n);
        s=0;
        for (j=0; j<n; j++) {
            fscanf (in,"%d",&k);
            s^=k;
        }
        if (s) fprintf (out,"DA\n");
        else fprintf (out,"NU\n");
    }
    fclose (in); fclose (out);
    return 0;
}
