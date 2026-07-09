#include<cstdio>
using namespace std;
long long t,a,b;
unsigned int i;
unsigned long long cmmdc (unsigned long long a,unsigned long long b)
{
    if(!b)return a;
    else return cmmdc(b,a%b);
}
int main()
{
    FILE *f=fopen("euclid2.in","r");
    FILE *g=fopen("euclid2.out","w");
    fscanf(f,"%lld",&t);
    for(i=1;i<=t;++i)
    {
        fscanf(f,"%lld%lld",&a,&b);
        fprintf(g,"%lld\n",cmmdc(a,b));
    }
    return 0;
}
