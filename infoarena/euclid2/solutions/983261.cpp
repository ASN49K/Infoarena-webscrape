#include <cstdio>

using namespace std;
int cmmdc(int a, int b)
{
    int t;
    while(!b)
    {
     t=b;
     b=b%a;
     a=t;
    }
    return a;
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int n,a,b,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d \n",cmmdc(a,b));
    }
    return 0;
}
