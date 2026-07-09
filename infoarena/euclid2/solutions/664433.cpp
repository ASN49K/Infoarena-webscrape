#include<cstdio>
using namespace std;
int n,a,b,nr,i;
int cmmdc(int a,int b)
{
    if (!b) return a;
    return cmmdc(b,a%b);
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        nr=cmmdc(a,b);
        printf("%d\n",nr);
    }
    return 0;
}
