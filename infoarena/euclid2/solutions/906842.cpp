#include <stdio.h>
using namespace std;
FILE*F=fopen("euclid2.in","r");
FILE*G=fopen("euclid2.out","w");
int cmmdc(int a,int b)
{
    if(b)
        cmmdc(b,a%b);
    else
        return a;
}
int main()
{
    int t,a,b;
    fscanf(F,"%d",&t);
    for(int i=1;i<=t;i++)
    {
        fscanf(F,"%d%d",&a,&b);
        fprintf(G,"%d\n",cmmdc(a,b));
    }
    return 0;
}
