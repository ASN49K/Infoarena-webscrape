#include <stdio.h>

using namespace std;

FILE *f,*g;

int main ()
{
    f=fopen("euclid2.in","r");
    g=fopen("euclid2.out","w");
    int n,a,b,r,i;
    fscanf(f,"%d",&n);
    for (i=1; i<=n; i++)
    {
        fscanf(f,"%d %d",&a,&b);
        if (a%b==0)
            fprintf(g,"%d\n",b);
        else
        {
            while (a%b)
            {
                r=a%b;
                a=b;
                b=r;
            }
            fprintf(g,"%d\n",r);
            r=0;
        }
    }
    fclose(f);
    fclose(g);
}
