#include <cstdio>

FILE *in,*out;

using namespace std;

int t,n,x,y;
int main()
{
    in=fopen("nim.in","rt");
    out=fopen("nim.out","wt");
    fscanf(in,"%d",&t);
    for(int i=1; i<=t; i++)
    {
        y=0;
        fscanf(in,"%d",&n);
        for(int j=1; j<=n; j++)
        {
            fscanf(in,"%d",&x);
            y=y^x;
        }
        if(y)
            fprintf(out,"DA");
        else
            fprintf(out,"NU");
        fprintf(out,"\n");
    }
    fclose(in);
    fclose(out);
    return 0;
}
