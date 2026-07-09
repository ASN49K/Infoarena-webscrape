#include <cstdio>

using namespace std;

int cmmdc(int a,int b)
{
    int r=a%b;
    while(r)
    {
        a=b;b=r;
        r=a%b;
    }
    return b;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int n,x,y;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",cmmdc(x,y));
    }
}
