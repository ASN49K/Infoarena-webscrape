#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a, int b)
{
    if(b<=0)
        return a;
    cmmdc(b,a%b);
}

int main()
{
    FILE * fin = fopen("euclid2.in","r");
    FILE * fout = fopen("euclid2.out","w");

    int n,a,b,i;
    fscanf(fin,"%d",&n);

    for(i=0;i<n;i++)
    {

        fscanf(fin,"%d %d",&a,&b);
        fprintf(fout,"%d\n",cmmdc(a,b));
    }
    return 0;
}
