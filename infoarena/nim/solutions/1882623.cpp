#include <stdio.h>

int t, n;

int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d ",&t);
    while(t--)
    {
        scanf("%d ",&n);
        int a,b;
        scanf("%d ",&a);
        for(int i=1;i<n;i++)
        {
            scanf("%d ",&b);
            a^=b;
        }
        printf("%s\n",a?"DA":"NU");
    }
    return 0;
}
