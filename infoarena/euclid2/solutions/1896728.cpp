#include <cstdio>
#include <fstream>
using namespace std;

int main()
{
    FILE *f=fopen("euclid2.in","r");
    FILE *g=fopen("euclid2.out","w");
    int n,a,b,x,y,r;
    fscanf(f,"%d",&n);
    for(int i=0;i<n;i++)
    {
        fscanf(f,"%d%d",&a,&b);
        x=a;y=b;
        while(y)
        {
            r=x%y;
            x=y;
            y=r;
        }
        fprintf(g,"%d\n",x);
    }
    fclose(f);
    fclose(g);
    return 0;
}
