#include <stdio.h>
using namespace std;
FILE *f, *g;

int n,a,b,r;
int main()
{
    f=fopen("euclid2.in","r");
    g=fopen("euclid2.out","w");
    fscanf(f,"%d",&n) ;
    for(int i=1; i<=n; i++)
    {
        fscanf(f,"%d %d",&a,&b) ;
        do
        {
            r=a%b;
            a=b;
            b=r;
        }while(r);
        fprintf(g,"%d%c",a,'\n');
    }
    fclose(f);
    fclose(g);
    return 0;
}
