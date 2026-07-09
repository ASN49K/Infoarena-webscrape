#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n,x,y,i,d;
    FILE *f = fopen("euclid2.in","r");
    FILE *g = fopen("euclid2.out","w");
    fscanf(f,"%d",&n);
    for (i=0;i<n;i++) {
        fscanf(f,"%d %d",&x,&y);
        while (y) {
            d = x % y;
            x = y;
            y = d;
        }
        fprintf(g,"%d\n",x);
    }
    return 0;
}
