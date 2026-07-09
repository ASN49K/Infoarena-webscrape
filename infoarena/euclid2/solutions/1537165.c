#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fin,*fout;
    fin=fopen ("euclid2.in","r");
    fout=fopen ("euclid2.out","w");

    int n,i,a,b,r;

    fscanf (fin,"%d",&n);

    for (i=1; i<=n; i++)
    {
        fscanf (fin,"%d",&a);
        fscanf (fin,"%d",&b);

        while (b>0)
        {
            r=a%b;
            a=b;
            b=r;
        }

        fprintf (fout,"%d",a);
        fputc ('\n',fout);
    }

    fclose (fin);
    fclose (fout);
    return 0;
}
