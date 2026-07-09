#include <stdio.h>
long a,x,i,j,t,n;
int main()
{
    FILE*f1,*f2;
    f1=fopen("nim.in","r");
    f2=fopen("nim.out","w");
    fscanf(f1,"%ld",&t);
    for(j=0;j<t;j++)
    {
        fscanf(f1,"%ld",&n);
        x=0;
        for(i=0;i<n;i++)
        {
            fscanf(f1,"%ld",&a);
            x=x xor a;
        }
        if(x)
            fprintf(f2,"DA\n");
        else fprintf(f2,"NU\n");
    }
    return 0;
}
