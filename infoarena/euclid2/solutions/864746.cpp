#include <stdio.h>
FILE *in,*out;
using namespace std;
int T,i,a[1001],b[1001],rest[1001],u;
int main()
{
    in=fopen("euclid2.in","rt");
    out=fopen("euclid2.out", "wt");
    fscanf(in, "%d", &T);
    for (i=1; i<=T; i++)
    {


      fscanf(in, "%d%d", &a[i], &b[i]);
    while (b[i])
     {
         rest[i]=a[i]%b[i];
         a[i]=b[i];
         b[i]=rest[i];

     }
     fprintf(out, "%d\n", a[i]);
    }

    fclose(in);
    fclose(out);
    return 0;
}
