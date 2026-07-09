#include <stdio.h>
#include <stdlib.h>

long int cmmdc(long int a,long int b){
    long int r;
    while (b) {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    long int n,x[100],a,b;
    int i;
    FILE *fpr;
    fpr=fopen("euclid2.in","r");
    fscanf(fpr,"%ld",&n);
    for(i=0;i<n;i++){
        fscanf(fpr,"%ld%ld",&a,&b);
        x[i]=cmmdc(a,b);
    }
    fclose(fpr);
    FILE *fpw;
    fpw=fopen("euclid2.out","w");
    for(i=0;i<n;i++){
        fprintf(fpw,"%ld\n",x[i]);
    }
    fclose(fpw);
    return 0;
}

