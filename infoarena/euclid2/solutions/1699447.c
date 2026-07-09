#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, a, b, r;
    FILE*fi,*fo;
    fi=fopen("euclid2.in","r");
    fo=fopen("euclid2.out","w");
    fscanf(fi,"%d", &n);
    for(i=0;i<n;i++){
        fscanf(fi,"%d%d", &a, &b);
        while(b>0){
            r=a%b;
            a=b;
            b=r;
        }
        fprintf(fo,"%d\n", a);
    }
    fclose(fi);
    fclose(fo);
    return 0;
}
