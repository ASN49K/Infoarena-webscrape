#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fin,*fout;
    int n,a,b,r;
    fin=fopen("euclid2.in","r");
    fout=fopen("euclid2.out","w");
    fscanf(fin,"%d", &n);
    while (n>0) {
        fscanf(fin,"%d%d", &a, &b);
            while (b>0) {
                r=a%b;
                a=b;
                b=r;
            }
        fprintf(fout,"%d\n", a);
        n--;
    }
    return 0;
}
