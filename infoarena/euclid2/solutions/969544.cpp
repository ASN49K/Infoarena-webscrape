#include <iostream>
#include <cstdio>
#define CLOSE fclose(in); fclose(out); return 0;

using namespace std;

int cmmdc(int a, int b){
    int r=a%b;
    while(b){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    FILE *in=fopen("euclid2.in","r");
    FILE *out=fopen("euclid2.out","w");

    int Q,a,b,r;
    fscanf(in,"%d",&Q);
    ++Q;
    while(--Q){
        fscanf(in,"%d%d",&a,&b);
        r=cmmdc(a,b);
        fprintf(out,"%d\n",r);
    }
    CLOSE
}
