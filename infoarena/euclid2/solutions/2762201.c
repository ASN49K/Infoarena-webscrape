#include <stdio.h>
#include <stdlib.h>

int main()
{   FILE* pf = fopen("euclid2.in","r");
    FILE* pf1 = fopen("euclid2.out","w");
    int a,b,r;
    fscanf(pf,"%d%d",&a,&b);
    while(b)
    {   r=a%b;
        a=b;
        b=r;

    }
    if(a==1)
    {   a=0;

    }
    fprintf(pf1,"%d",a);
    return 0;
}
