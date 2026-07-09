#include <stdio.h>
#include <stdlib.h>
long long euc(long long a,long long b)
{
    if (b==0) return a;
        else return euc(b,a%b);
}
int main()
{
    FILE *f,*p;
    f=fopen("euclid2.in","r");
    p=fopen("euclid2.out","w");
    int i;
    fscanf(f,"%d",&i);
    for (int j=0;j<i;j++)
    {
        long long a,b;
        fscanf(f,"%lld %lld",&a,&b);
        fprintf(p,"%lld\n",euc(a,b));
    }
    fclose(p);fclose(f);
    return 0;
}
