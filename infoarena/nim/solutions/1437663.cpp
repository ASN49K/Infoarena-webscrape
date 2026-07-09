#include <cstdio>
using namespace std;

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);
    int t,n,a,s=0,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        s=0;
        for(i=0;i<n;++i)
        {
            scanf("%d",&a);
            s=s^a;
        }
        if(s)
            printf("DA\n");
        else
            printf("NU\n");
    }
    return 0;
}
