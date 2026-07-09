#include <stdio.h>
#include <math.h>
int n,a,b,r,i;
int main()
{
    FILE* si=fopen("euclid2.in","r");
    FILE* so=fopen("euclid2.out","w");
    fscanf(si,"%i",&n);
    for(i=0; i<n; i++)
    {
        fscanf(si,"%i%i",&a,&b);
        while(b>0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fprintf(so,"%i\n",a);
    }
    fclose(si);
    fclose(so);
    return 0;
}
