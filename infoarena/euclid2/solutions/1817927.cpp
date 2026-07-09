#include <cstdio>

using namespace std;

int cmmdc(int a, int b)
{
    if(!b)return a;
    else return (cmmdc(b,a%b));
}


int main()
{
    FILE *f=fopen("euclid2.in","r"),*g=fopen("euclid2.out","w");
    int n,a,b;
    fscanf(f,"%d",&n);
    for(;n;--n)
    {
        fscanf(f,"%d%d",&a,&b);
        fprintf(g,"%d\n",cmmdc(a,b));
    }


    return 0;
}
