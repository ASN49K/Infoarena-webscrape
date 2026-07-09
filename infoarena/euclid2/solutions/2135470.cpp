#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    FILE *fin,*fout;
    fin=fopen("euclid2.in","r");
    fout=fopen("euclid2.out","w");
    int n,i,a,b,r;
    fscanf(fin,"%d",&n);
    for (i=1;i<=n;i++)
    {
        fscanf(fin,"%d%d",&a,&b);
        r=a%b;
        while (r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        fprintf(fout,"%d\n",b);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
