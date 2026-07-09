#include <stdio.h>
#include <stdlib.h>

int euclid(int a,int b)
{
    if(b==0) return a;
    return euclid(b,a%b);
}

int main()
{
    int n,a,b;
    FILE *f;
    f=fopen("dat.in","r");

    fscanf(f,"%d",&n);
    for(int i=0;i<n;i++)
    {
        fscanf(f,"%d",&a);
        fscanf(f,"%d",&b);
        printf("%d\n",euclid(a,b));
    }
fclose(f);
fflush(stdout);
return 0;
}
