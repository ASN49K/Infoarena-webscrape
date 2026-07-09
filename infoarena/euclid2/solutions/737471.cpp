#include <cstdio>
using namespace std;

int cmmdc(int a,int b)
{
    int aux;
    while (b != 0)
    {
        aux = a % b;
        a = b;
        b = aux;
    }
    return a;
}

void citire()
{
    int n,a,b;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf ("%d",&n);
    for (int i = 1;i <= n;++i)
    {
        scanf ("%d%d",&a,&b);
        printf ("%d\n",cmmdc(a,b));
    }
}

int main()
{
    citire();
    return 0;
}
