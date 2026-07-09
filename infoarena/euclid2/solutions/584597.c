#include <stdio.h>
#include <stdlib.h>
int euclid(int a , int b)
{

    if(a==b)
    return a;
    if(a>b)
    euclid(a-b,b);
    if(a<b)
    euclid(a,b-a);
}
int main()
{
    int n,a,b,i;
    FILE *f,*g;
    f=fopen("euclid2.int","r");
    g=fopen("euclid12.out","w");
    fscanf(f,"%d",&n);
    for(i=0;i<n;i++)
    {
        fscanf(f,"%d",&a);fscanf(f,"%d",&b);
        fprintf(g,"%d",euclid(a,b));
    }
    fclose(f);
    fclose(g);
    return 0;
}
