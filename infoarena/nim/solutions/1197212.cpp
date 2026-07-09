#include <cstdio>

using namespace std;



int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);
    int t, n, a,sum,i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        sum = 0;
        for(i=1; i<=n;++i)
        {
            scanf("%d", &a);
            sum=sum^a;
        }

        if(sum)
            printf("DA\n");
        else
            printf("NU\n");
    }

    return 0;
}
