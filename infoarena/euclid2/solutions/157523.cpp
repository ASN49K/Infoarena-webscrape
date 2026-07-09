#include<stdio.h>

FILE *fin=fopen("euclid2.in","r");
FILE *fout=fopen("euclid2.out","w");

long int cmmdc(long int a,long int b)
{
     if(!b) return a;
     return cmmdc(b,a%b);
}

int main()
{
    long int t,a,b;
    fscanf(fin,"%ld",&t);
    
    for(;t;t--)
    {
       fscanf(fin,"%ld %ld",&a,&b);
       fprintf(fout,"%ld\n",cmmdc(a,b));
    }
    
    fclose(fout);
    return 0;
} 
