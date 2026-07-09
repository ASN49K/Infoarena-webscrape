#include <stdio.h>
using namespace std;
FILE*fin=fopen("euclid2.in","r");
FILE*fout=fopen("euclid2.out","w");
int main()
{
    int n,i;
    fscanf(fin,"%d",&n);
    for(i=1; i<=n; i++)
    {
        int a,b,r;


        fscanf(fin,"%d %d",&a,&b);
        while (b>0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fprintf(fout,"%d\n",a);
    }
    return 0;
}
