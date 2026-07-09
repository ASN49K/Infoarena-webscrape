#include <cstdio>

using namespace std;

int cmmdc(int a, int b)
{
    if(b==0)
        return a;
    return cmmdc(b,a%b);
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int i, n, a, b;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",cmmdc(a,b));
    }
    return 0;
}
