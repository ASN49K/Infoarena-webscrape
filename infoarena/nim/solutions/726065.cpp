#include <stdio.h>

using namespace std;

int main()
{
    freopen ("nim.in","r",stdin);
    freopen ("nim.out","w",stdout);

    int n,ni,x;
    scanf("%d", &n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d", &ni);
        int s=0;
        for(int j=1;j<=ni;++j)
            scanf("%d", &x),
            s = s^x;

        if(!s)  printf("NU\n");
        else    printf("DA\n");
    }
    return 0;
}
