#include<stdio.h>
using namespace std;

FILE *in=fopen("nim.in","r");
FILE *out=fopen("nim.out","w");

int main()
{
    int t,n,i,x,s;

    fscanf(in,"%d",&t);
    while(t--)
    {
        fscanf(in,"%d",&n);

        s=0;
        while(n--)
        {
            fscanf(in,"%d",&x);
            s^=x;
        }

        if(s==0) fprintf(out,"NU\n");
        else fprintf(out,"DA\n");
    }

    return 0;
}
