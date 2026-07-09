#include "stdio.h"

using namespace std;

int main()
{
    int n,a,b,r;

    FILE* f=fopen("euclid2.in","r");
    FILE* g=fopen("euclid2.out","w");

    fscanf(f,"%i",&n);
    for(int i=0;i<n;i++)
    {
        fscanf(f,"%i",&a);
        fscanf(f,"%i",&b);

        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }

        fprintf(g,"%i\n",a);
    }

    fclose(f);
    fclose(g);

    return 0;
}
