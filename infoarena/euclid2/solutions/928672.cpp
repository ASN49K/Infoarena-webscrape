#include <cstdio>
using namespace std;
FILE*fin=fopen("euclid2.in","r");
FILE*fout=fopen("euclid2.out","w");
int a,b,r,i,j,k,m,l,n,w[100];
int main()
{
    fscanf(fin,"%d",&n);
    for (i=1;i<=n;i++)
    {fscanf(fin,"%d%d",&a,&b);
    for (r=a%b;r!=0;a=b,b=r,r=a%b);
    fprintf(fout,"%d\n",b);
    }
    return 0;
}
