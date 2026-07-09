#include<cstdio>
#include<fstream>
using namespace std;
FILE *f=fopen("euclid2.in","r");
ofstream g("euclid2.out");
int main()
{
    int n,a,b,r,i;
    fscanf(f,"%d",&n);
    for(i=1;i<=n;i++)
    {
        fscanf(f,"%d%d",&a,&b);
        r=a%b;
        while(r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        g<<b<<'\n';
    }
    return 0;
}
