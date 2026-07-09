#include <stdio.h>
int a,b,r,i,n;
FILE*fin,*fout;
int main()
{
    fin=fopen("euclid2.in","r");
    fout=fopen("euclid2.out","w");
    fscanf(fin,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fin,"%d %d",&a,&b);
        r=a%b;
        while(r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        fprintf(fout,"%d\n",b);
    }

        return 0;
    }
