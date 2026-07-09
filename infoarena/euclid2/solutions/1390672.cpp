#include <stdio.h>

using namespace std;

FILE*f=fopen("euclid2.in","r"),*g=fopen("euclid2.out","w");
long long a, b;
int n;

long long cmmdc(long long a, long long b)
{
    long long r = 1;
    while(r != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    fscanf(f,"%d", &n);
    for(int i = 1; i <= n; i++)
    {
        fscanf(f,"%lld %lld\n",&a,&b);
        long long x = cmmdc(a,b);
        fprintf(g,"%lld\n",x);
    }
    return 0;
}
