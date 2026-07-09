#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *in=fopen("euclid2.in.txt","r");;
    FILE *out=fopen("euclid2.out.txt","w");;
    int t,a,b,c,i;

    fscanf(in,"%d",&t);
    for (i=1;i<=t;i++)
        {
         fscanf(in,"%d %d",&a,&b);
         c=a%b;
           while (c!=0)
           {
            a=b;
            b=c;
            c=a%b;
           }

        fprintf(out,"%d\n",b);
        }
        fclose(in);
        fclose(out);
    return 0;
}
