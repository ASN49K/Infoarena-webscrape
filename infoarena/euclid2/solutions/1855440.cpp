#include <cstdio>

using namespace std;
int t,a,b;
int cmmdc(int a,int b)
{
    int r=0;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;

    }
    return a;
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&t);
    for(;t;t--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",cmmdc(a,b));
    }
    return 0;
}
