#include <iostream>
#include <fstream>
using namespace std;
FILE *f=fopen("nim.in","r"),*g=fopen("num.out","w");
long long t,n,s,i,j,a;
int main()
{
    fscanf(f,"%lld",&t);
    for(i=1;i<=t;i++)
    {
        fscanf(f,"%lld",&n);
        s=0;
        for(j=1;j<=n;j++)
        {
            fscanf(f,"%lld",&a);
            s=s^a;
        }
        if(s==0)
            fprintf(g,"NU\n");
        else
            fprintf(g,"DA\n");
    }
    return 0;
}
