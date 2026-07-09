#include <stdio.h>
#include <stdlib.h>
int gcd(int n, int m)
{
    if (!m)//m==0
     return n;
    return gcd(m,n%m);
}
int main()
{
    int N,a,b,P,T;
    FILE *f=fopen("euclid2.in","r");
    FILE *g=fopen("euclid2.out","w");
    fscanf(f,"%d",&T);
    while(T>0)
    {
        fscanf(f,"%d %d\n",&a,&b);
        P=gcd(a,b);
        fprintf(g,"%d",P);
        fprintf(g,"\n");
       // printf("%d %d\n",a,b);
        T--;
    }
     
    return 0;
}
