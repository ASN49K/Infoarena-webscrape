#include <cstdio>
FILE *g=fopen("euclid2.in","r");
FILE *z=fopen("euclid2.out","w");
using namespace std;

int main()
{
    int a,b,n,r;
    fscanf(g,"%d",&n);
    for(int i=1;i<=n;i++)
    {
        fscanf(g,"%d%d",&a,&b);
        while(b)
        {
            r=b;
            b=a%b;
            a=r;
        }
        fprintf(z,"%d\n",r);
    }
    return 0;
}
