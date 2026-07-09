#include <cstdio>

using namespace std;
int cmmdc(int a, int b)
{
    if(!b)return a;
        return cmmdc(b,b%a);
}
int main()
{
    int n,a,b,i;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d \n",cmmdc(a,b));
    }
    return 0;
}
