#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;



int CMMDC(long a, long b){
    long r;
    r=a%b;
    while(r){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main()
{
    int T;
    long a,b;
    FILE *f = fopen("euclid2.in","r");
    FILE *g = fopen("euclid2.out","w");

    for(fscanf(f,"%d",&T);T>=1;T--){
        fscanf(f,"%d%d",&a,&b);
        fprintf(g,"%d\n",CMMDC(a,b));
    }

    fclose(f);
    fclose(g);
    return 0;
}
