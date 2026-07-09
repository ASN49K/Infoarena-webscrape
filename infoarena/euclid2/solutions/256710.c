#include<stdio.h>
#include<stdlib.h>
int euclid(int a, int b)
{
    int aux;
    if(a==0)
        return b;
    if(b==0)
        return a;
    while(b>0)
    {
        aux=a%b;
        a=b;
        b=aux;
    }
    return a;
}

int main()
{
    int a, b, n, i;
    FILE *f = fopen("euclid2.in" , "rt");
    FILE *g = fopen("euclid2.out" , "wt");
    fscanf(f , "%d" , &n);
    for(i=0;i<n;i++)
    {
        fscanf(f , "%d%d" , &a , &b);
        fprintf(g, "%d\n" , euclid(a, b));
    }
    fclose(f);
    fclose(g);
    return 0;
}
