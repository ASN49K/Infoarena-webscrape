#include <cstdio>
using namespace std;
int  cmmmdc(int a, int b)
{
    int r=1;
    if(b==0)return a;
    while(r)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int n,i,a,b,c;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        c=cmmmdc(a,b);
        printf("%d\n",c);
    }
    return 0;
}
