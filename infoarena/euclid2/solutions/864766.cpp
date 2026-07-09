#include <stdio.h>
FILE *in,*out;
using namespace std;
int T,a,b,rest,i;

int main()
{
    in=fopen("euclid2.in","rt");
    out=fopen("euclid2.out", "wt");
    fscanf(in, "%d", &T);
    for (i=1; i<=T; i++)
    {


      fscanf(in, "%d%d", &a, &b);

    while (b!=0)
     {
         rest=a%b;
         a=b;
         b=rest;

     }
     fprintf(out, "%d\n", a);
    }

    fclose(in);
    fclose(out);
    return 0;
}
