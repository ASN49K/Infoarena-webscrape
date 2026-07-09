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

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        int s=cmmdc(a,b);
        printf("%d\n",s);
    }

    return 0;
}
