#include<stdio.h>
using namespace std;

int t,n,sum;

void solve()
{
    int x;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&n); sum=0;
        for(int j=1;j<=n;j++) scanf("%d",&x),sum^=x;
        if(sum) printf("DA\n");
        else printf("NU\n");
    }
}

int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);

    solve();

    fclose(stdin);
    fclose(stdout);
    return 0;
}

