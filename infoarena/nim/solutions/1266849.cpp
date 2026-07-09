#include<cstdio>
using namespace std;
int n,m,i,T;
int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d",&T);
    for (i=1;i<=T;++i)
    {
        scanf("%d",&n);
        int s=0;
        for (i=1;i<=n;++i)
        {
            scanf("%d",&m);
            s=s^m;
        }
        if (s>0) printf("DA\n");
            else printf("NU\n");
    }
}
