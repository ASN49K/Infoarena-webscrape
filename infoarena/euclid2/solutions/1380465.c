#include<stdio.h>


int main()
{
    FILE* f = fopen("euclid2.in","r");
    FILE* g = fopen("euclid2.out","w");

    int t,a,b,r,i;
    fscanf(f,"%d",&t);

    for (i = 0; i < t; i++)
    {
        fscanf(f,"%d%d",&a,&b);

        r = a % b;
        while (r != 0)
        {
            a = b;
            b = r;
            r = a % b;
        }

        fprintf(g,"%d\n",b);
    }


    fclose(f);
    fclose(g);

    return 0;
}
