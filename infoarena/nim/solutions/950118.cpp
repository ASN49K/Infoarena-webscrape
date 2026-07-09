#include <cstdio>

using namespace std;

int t,n,a,XOR;

int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w", stdout);
    scanf("%d", &t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        XOR=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&a);
            XOR=XOR^a;
        }
        if(XOR>0)
            printf("DA\n");
        else
            printf("NU\n");
    }
    return 0;
}
