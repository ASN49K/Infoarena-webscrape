#include <stdio.h>
#include <math.h>


int main()
{
    FILE* f;
    FILE* g;
    f=fopen("euclid2.in","r");
    g=fopen("euclid2.out","w");

    int a, b, T, cmmdc=0, min;

    fscanf(f,"%d",&T);

    for(int i=1;i<=T;i++)
    {
        fscanf(f,"%d%d",&a,&b);
        if (a < b)
        {
            min=a;
        }
            else min=b;
            for(int q=1;q<=min;q++)
            {
                if (a % q == 0 && b % q == 0 && q > cmmdc)
                {
                    cmmdc=q;
                }
            }
        fprintf(g,"%d\n",cmmdc);
        cmmdc=0;
        if(feof(f))
        {
            break;
        }


    }

}
