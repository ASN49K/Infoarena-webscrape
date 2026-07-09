#include <cstdio>

using namespace std;

int n,a,b;

int cmmdc(int a,int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

void citire()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",cmmdc(a,b));
    }
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    citire();
    return 0;
}
