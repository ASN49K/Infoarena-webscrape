#include <stdio.h>

using namespace std;

int main()
{
    FILE *f=fopen("euclid2.in","r");
    FILE *f2=fopen("euclid2.out","w");
    int a,b;
    int n;
    int r,i;
    fscanf(f,"%d",&n);
    for(i=1;i<=n;i++)
    {fscanf(f,"%d%d",&a,&b);
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    fprintf(f2,"%d\n",a);
    }
    return 0;
}
