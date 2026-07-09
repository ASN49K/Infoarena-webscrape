#include <stdio.h>
long a,b,x,i,j,t,n;
int main()
{
    FILE*f1,*f2;
    f1=fopen("nim.in","r");
    f2=fopen("nim.out","w");
    fscanf(f1,"%ld",&t);
    for(j=0;j<t;j++)
    {
        fscanf(f1,"%ld",&n);
        if(n>1)
        {
            fscanf(f1,"%ld%ld",&a,&b);
            x=a xor b;
            for(i=2;i<n;i++)
            {
                fscanf(f1,"%ld",&a);
                x=x xor a;
            }
            if(x)fprintf(f2,"%DA\n");
            else fprintf(f2,"NU\n");
        }
        else fprintf(f2,"DA\n");
    }
    return 0;
}
