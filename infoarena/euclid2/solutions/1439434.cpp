#include <fstream>
using namespace std;
FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");
int main()
{
    int a,b,n,i,c;
    fscanf(f,"%d",&n);
    for(i=1;i<=n;i++)
    {
        fscanf(f,"%d %d",&a,&b);
        while(a%b!=0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        fprintf(g,"%d \n",b);
    }
    return 0;
}
