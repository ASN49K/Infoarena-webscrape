// Algoritmul lui Euclid
// cmmdc - gcd

#include <stdio.h>
#include <stdlib.h>

unsigned int gcd(unsigned int a,unsigned int b)
{
    unsigned int aux;
    if (a<b) {aux=b;b=a;a=aux;}
    unsigned int rest=1;
    do
    {
        rest=a%b;
        a=b;b=rest;
    }
    while (rest!=0);
    return a;
}

int main()
{
    int t,i;
    unsigned int a,b;
    FILE *f,*g;
    f=fopen("euclid2.in","r");
    g=fopen("euclid2.out","w");

    fscanf(f,"%d",&t);
    for (i=0;i<t;i++)
    {
        fscanf(f,"%d %d",&a, &b);
        fprintf(g,"%d\n",gcd(a,b));
    }
    return 0;
}
