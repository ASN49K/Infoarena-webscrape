#include<cstdio>
using namespace std;

FILE *fin=fopen("euclid2.in","r");
FILE *fout=fopen("euclid2.out","w");


int n,i,a,b,r;

int main()
{
    fscanf(fin,"%d",&n);
    for(i=1;i<=n;i++)
    {
        fscanf(fin,"%d%d",&a,&b);
        r=a%b;
        while(r)
        {
            a=b;
            b=r;
            r=a%b;
        }
        fprintf(fout,"%d\n",b);
    }



    return 0;
}
