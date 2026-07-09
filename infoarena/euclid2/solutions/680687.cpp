#include <stdio.h>

using namespace std;

int main()
{
    FILE *F=fopen("euclid2.in","r"),*G=fopen("euclid2.out","w");
    int t,i,a,b,r;
    fscanf(F,"%d",&t);
    for(i=1;i<=t;i++)
    {
        fscanf(F,"%d%d",&a,&b);
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fprintf(G,"%d\n",a);
    }
    return 0;
}
