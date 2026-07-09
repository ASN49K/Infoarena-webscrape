#include<cstdio>
using namespace std;
int main()
{
    int t,n,x,a;
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        x=0;
        scanf("%d",&n);
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a);
            x^=a;
        }
        if(x) printf("DA\n");
        else printf("NU\n");
    }
}
