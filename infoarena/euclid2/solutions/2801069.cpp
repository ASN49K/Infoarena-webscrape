#include <stdio.h>
using namespace std;
FILE *fin,*fout;
int main ()
{
    int a,n,b,k,k1=1;
    fin=fopen("euclid2.in","r");
    fout=fopen("euclid2.out","w");
    fscanf(fin,"%d",&n);
    while(n)
    {fscanf(fin,"%d%d",&a,&b);
    while(b)
        {k=a%b;
         a=b;
         b=k;
            }
    fprintf(fout,"%d\n",a);n--;
    }
  return 0;
}
