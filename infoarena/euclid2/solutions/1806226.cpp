#include <cstdio>

using namespace std;

int cmmdc(int a,int b)
{
    if(b==0) return a;
    return cmmdc(b,a%b);
}

int main()
{
    FILE *f=fopen("euclid2.in","r");
    FILE *g=fopen("euclid2.out","w");
    int a,b,n;
    fscanf(f,"%d",&n);
    while(n--)
    {
        fscanf(f,"%d%d",&a,&b);
        fprintf(g,"%d\n",cmmdc(a,b));
    }
    return 0;
}
