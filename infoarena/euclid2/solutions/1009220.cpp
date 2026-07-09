#include <stdio.h>
int main ()
{
    FILE *fin=fopen("euclid2.in","r");
    FILE *fout=fopen("euclid2.out","w");
    int i,n,a,b,r;
    fscanf(fin,"%d",&n);
    for(i=0;i<n;i++)
    {
        fscanf(fin,"%d %d",&a,&b); 
        while(r=a%b)
        {
            a=b;
            b=r;
        } 
        fprintf(fout,"%d",b);
    }
    return 0;
}
