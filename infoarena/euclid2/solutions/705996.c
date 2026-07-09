#include<stdio.h>

long cmmdc(long x,long y)
{
    if(!y) return x;
    return cmmdc(y,x%y);
}

int main()
{
    FILE *fin,*fout;
    long t,a,b,i;

    fin=fopen("euclid2.in","rt");
    fout=fopen("euclid2.out","wt");

    fscanf(fin,"%ld",&t);
    for(i=1;i<=t;i++)
        {
            fscanf(fin,"%ld%ld",&a,&b);
            fprintf(fout,"%ld\n",cmmdc(a,b));
        }

    fclose(fin);
    fclose(fout);

    return 0;
}
