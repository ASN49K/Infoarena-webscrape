#include <stdio.h>

long cmmdc(long,long);

int main(void)
{
    FILE *fin,*fout;
    long t,a,b,i;
    
    fin = fopen("euclid2.in", "r");
    fout = fopen("euclid2.out", "w");
    
    if(fin == NULL)return 0;
    
    fscanf(fin,"%ld\n", &t);
    
    for(i = 0;i < t;i++)
    {
        fscanf(fin,"%ld %ld\n", &a, &b);
        fprintf(fout,"%ld\n",cmmdc(a,b));
    }
    
    fclose(fin);
    fclose(fout);
    return 0;
}

long cmmdc(long a,long b)
{
    while(a != 0 && b != 0)
    {
        if(a > b)a = a % b;
        else b = b % a;
    }
    if(a == 0)return b;
    else return a;
}
