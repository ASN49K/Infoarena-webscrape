#include <stdio.h>

using namespace std;

FILE*f=fopen("euclid2.in","r"),*g=fopen("euclid2.out","w");
long long a, b;
int n;

int cmmdc(long long a, long long b)
{
    long long r;
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
        int x = cmmdc(a,b);
        fprintf(g,"%d\n",x);
    }
    return 0;
}
