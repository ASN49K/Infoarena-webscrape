#include <stdio.h>

int cmmdc(int,int);

int main(void)
{
    FILE *fin,*fout;
    long t,a,b,i;
    
    fin = fopen("euclid2.in", "r");
    fout = fopen("euclid.out", "w");
    
    if(fin == NULL)return 0;
    
    fscanf(fin,"%d\n", &t);
    
    for(i = 0;i < t;i++)
    {
        fscanf(fin,"%d %d\n", &a, &b);
        fprintf(fout,"%d\n",cmmdc(a,b));
    }
    
    fclose(fin);
    fclose(fout);
    return 0;
}

int cmmdc(int a,int b)
{
    while(a != 0 && b != 0)
    {
        if(a > b)a = a % b;
        else b = b % a;
    }
    if(a == 0)return b;
    else return a;
}
