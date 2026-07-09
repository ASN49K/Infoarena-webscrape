#include <stdio.h>
using namespace std;
FILE *fin,*fout;
int v[21];
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

    v[k1]=a;
    k1++;
    if(k1==21)
    {
        fprintf(fout,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",v[1],v[2],v[3],v[4],v[5],v[6],v[7],v[8],v[9],v[10],v[11],v[12],v[13],v[14],v[15],v[16],v[17],v[18],v[19],v[20]);
        k1=1;
    }n--;
    }
    if(k1!=1)
        for(n=1;n<=k1-1;n++)
            fprintf(fout,"%d\n",v[n]);
  return 0;
}
