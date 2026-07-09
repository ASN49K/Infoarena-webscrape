#include <fstream>

using namespace std;

FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");

int main()
{
    int n,i,a,b,r;
    fscanf(f,"%d",&n);
    for (i=1;i<=n;i++)
    {
        fscanf(f,"%d%d",&a,&b);
        r=a%b;
        while (r)
        {
            a=b;
            b=r;
            r=a%b;
        }
        fprintf(g,"%d\n",b);
    }
    return 0;
}
