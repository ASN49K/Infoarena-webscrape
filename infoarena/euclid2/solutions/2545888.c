#include <stdio.h>
#include <stdlib.h>
int euclid(int a,int b);
int main()
{
    FILE* f=fopen("euclid2.in","r");
    FILE* g=fopen("euclid2.out","w");
    if(f==NULL)
        return 0;
    int n,a,b,e;
    fscanf(f,"%d",&n);
    for(int i=0;i<n;i++)
    {
        fscanf(f,"%d%d",&a,&b);
        e=euclid(a,b);
        fprintf(g,"%d\n",e);
    }
}
int euclid(int a, int b)
{
    int c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
