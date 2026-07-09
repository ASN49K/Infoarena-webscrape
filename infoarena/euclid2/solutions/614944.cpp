#include <stdio.h>

long cmmdc ( long a, long b)
{
if (a==b) { if (a==1) return 0; else return a; }
else if (a>b) return cmmdc(b,a-b);
else return cmmdc(a,b-a);
}

int main()
{
    long a,b;
    FILE *f;
    FILE *g;	
    f = fopen("euclid2.in","r");
    g = fopen("euclid2.out","w");
    int t;
    fscanf(f,%d,&t);
    for (int i=1;i<=t;i++){

    fscanf(f,"%ld %ld",&a,&b);
    fprintf(g,"%ld\n",cmmdc(a,b));
}
    fclose(g);
    fclose(f);
    return 0;
}