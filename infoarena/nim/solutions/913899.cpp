#include <cstdio>

using namespace std;
int t,n,x,s;
int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);
        s=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            s=s^x;
        }
        if(s!=0)
            printf("DA\n");
        else
            printf("NU\n");
    }
    return 0;
}
