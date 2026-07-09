#include <fstream>

using namespace std;
FILE*fin=fopen("euclid2.in","r");
FILE*fout=fopen("euclid2.out","w");
int cmmdc (int a,int b)
{
    int r;
    while (b)
    {
        r=b;
        b=a%b;
        a=r;
    }
    return a;
}
int main()
{
    int x,y,n,i;
    fscanf(fin,"%d",&n);
    for (i=0;i<n;i++)
    {
        fscanf(fin,"%d%d",&x,&y);
        fprintf(fout,"%d\n",cmmdc(x,y));
    }
    return 0;
}
