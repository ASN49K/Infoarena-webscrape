#include <cstdio>
int n,t,x,y;
int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d",&t);
    for(;t;t--)
    {
        scanf("%d",&n);x=0;
        for(;n;n--){scanf("%d",&y);x^=y;};
        x?printf("DA\n"):printf("NU\n");
    }
    return 0;
}
