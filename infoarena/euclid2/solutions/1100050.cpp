#include <stdio.h>

using namespace std;

FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");

int T,a,b;

int c(int a,int b)
{
    if(b) return c(b,a%b);
    else return a;
}


int main()
{
    fscanf(f,"%d",&T);
    for(int i=1;i<=T;i++)
    {
        fscanf(f,"%d%d",&a,&b);
        fprintf(g,"%d\n",c(a,b));
    }
    return 0;
}
