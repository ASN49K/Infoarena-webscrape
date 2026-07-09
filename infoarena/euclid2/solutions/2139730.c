#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a, int b) {
    while(a>0 && b>0) {
        if(a>b) {
            a=a-b;
        }
        else {
            b=b-a;
        }
    }
    if(a==0) {
        return b;
    }
    else
        return a;
}


int main()
{
    int n,a,b,i,d;
    FILE* f;
    FILE* g;
    f = fopen("euclid2.in","r");
    g = fopen("euclid2.out","w");
    fscanf(f,"%d", &n);
    printf("%d",n);
    for(i=0;i<n;i++) {
        fscanf(f,"%d %d", &a, &b);
        d=cmmdc(a,b);
        fprintf(g, "%d \n", d);
    }
    fclose(f);
    //fclose(g);
    return 0;
}
