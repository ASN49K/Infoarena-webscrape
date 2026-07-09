#include <cstdio>
FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");
int r;
int cmmdc(int a,int b)
{
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int n;
int main()
{
    fscanf(f,"%d",&n);
    int i,a,b;
    for(i=1;i<=n;i++)
    {
        fscanf(f,"%d%d",&a,&b);
            fprintf(g,"%d\n",cmmdc(a,b));
    }
    return 0;
}
