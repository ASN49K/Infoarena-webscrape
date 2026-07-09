#include <stdio.h>
#include <math.h>


int main()
{
    FILE* f;
    FILE* g;
    f=fopen("euclid2.in","r");
    g=fopen("euclid2.out","w");

    long int a, b, T, cmmdc=0, min, max;

    fscanf(f,"%d",&T);

    for(int i=1;i<=T;i++)
    {
        fscanf(f,"%d%d",&a,&b);
        if (a < b)
        {
            min=a;
            max=b;
        }
            else
                {
                    max=a;
                    min=b;
                }

            for(int q=0;q<=min;q++)
            {
                cmmdc = max % min;
                max = min;
                min = cmmdc;
            }
        fprintf(g,"%d\n",max);

        if(feof(f))
        {
            break;
        }


    }

}
