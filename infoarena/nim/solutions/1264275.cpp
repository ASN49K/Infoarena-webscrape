#include <cstdio>
using namespace std;
int main()
{
    int n, t, i, j, x, sum;
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d",&t);
    for (i=1; i<=t; i++)
    {
        scanf("%d",&n);
        sum=0;
        for (j=1; j<=n; j++)
        {
            scanf("%d",&x);
            sum=sum^x;
        }
        if (sum!=0) printf("DA\n");
        else printf("NU\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
