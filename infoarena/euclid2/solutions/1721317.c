#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a,int b)
{
    if (b==0)
       return(a);
       else
       return cmmdc(b,a % b);
}

void citire()
{
    FILE *f,*g;
    int n,a,b,i;

    f=fopen("euclid2.in","r");
    g=fopen("euclid2.out","w");
    fscanf(f,"%d",&n);

    for (i=0; i<=n-1; i++)
    {
        fscanf(f,"%d %d",&a,&b);
        fprintf(g,"%d\n",cmmdc(a,b));
    }


    fclose(f);
    fclose(g);


}


int main()
{
    citire();
    return 0;
}
