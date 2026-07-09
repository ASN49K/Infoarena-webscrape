#include <fstream>
using namespace std;
FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");
int main()
{
    int a,b,n,i;
    fscanf(f,"%d",&n);
    for(i=1;i<=n;i++)
    {
        fscanf(f,"%d %d",&a,&b);
        while(a!=b)
        {
            if(a>b)
            a=a%b;
            else
            b=b%a;
        if(a==0){
            fprintf(g,"%d",b);
            return 0;
        }
    }
    }
    return 0;
}
