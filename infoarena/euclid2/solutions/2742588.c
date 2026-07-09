#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,x,y,r,rez,m=2,i,n,j;

    FILE *f_in, *f_out;

    f_in = fopen("euclid2.in", "r"); 
    f_out = fopen("euclid2.out", "w");
    fscanf (f_in,"%d",&n);

    for (i=0; i<n; i++){    
 
    fscanf(f_in,"%d%d",&a,&b);
    
    if (b>=a)
    {
        x=b;
        y=a;
    }
    else
    {
        x=a;
        y=b;
    }
    
    r=1;

    while (r!=0)
    {
        r=(x % y);
        x=y;
        y=r;
    }

    if (r==1) rez=0; else rez=x;
    
    fprintf(f_out,"%d\n",rez);  
    }

    fclose(f_in);
    fclose(f_out);

    return 0;
}
