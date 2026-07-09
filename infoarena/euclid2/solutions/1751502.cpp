#include<stdio.h>
using namespace std;
int cmmdc(int a,int b)
{
    if(b==0)
        return a;
    return cmmdc(b,a%b);
}
int main()
{
    int n,a,b;
    FILE *f=fopen("euclid2.in","r");
    FILE *g=fopen("euclid2.out","w");
    fscanf(f,"%d",&n);
    for(int i=1;i<=n;++i)
       {
           fscanf(f,"%d%d",&a,&b);
        fprintf(g,"%d\n",cmmdc(a,b));
       }
       fclose(f);
       fclose(g);
       return 0;
}
