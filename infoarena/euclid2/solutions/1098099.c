#include <stdio.h>
#include <stdlib.h>

int main()
{FILE *fin,*fout;
    int n,i,a,b,r;
    fin=fopen("euclid2.in","r");
    fout=fopen("euclid2.out","w");
    fscanf(fin,"%d",&n);
    for (i=0;i<n;i++) {
        fscanf(fin,"%d%d",&a,&b);
        while (b>0) {
            r=a%b;
            a=b;
            b=r;
        }
        fprintf(fout,"%d\n",a);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
