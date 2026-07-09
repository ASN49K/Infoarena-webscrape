#include <cstdio>

using namespace std;

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int n,a,b,x;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d %d",&a,&b);
        while(b!=0)
        {
            x=b;
            b=a%b;
            a=x;
        }
        printf("%d\n",a);
    }
    return 0;
}
