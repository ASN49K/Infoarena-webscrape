#include <cstdio>

using namespace std;

int cmmdc(int a, int b)
{
    if(b==0)
        return a;
    else
        return cmmdc(b,a%b);
}

int main()
{
    FILE *f=fopen("euclid2.in","r");
    FILE *g=fopen("euclid2.out","w");

    int n, i, a, b;

    fscanf(f, "%d", &n);

    for(i=1;i<=n;i++)
    {
        fscanf(f, "%d", &a);
        fscanf(f, "%d", &b);
        fprintf(g, "%d\n", cmmdc(a, b));
    }

    return 0;
}
