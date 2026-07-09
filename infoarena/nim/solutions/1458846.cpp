/*
pb de pe infoarena
#include <cstdio>
using namespace std;
int main()
{
    int n,tac,x,k;
    scanf("%d",&k);
    for(register int j=1; j<=k; ++j)
    {
        scanf("%d",&n);
        tac=0;
        for(register int i=1; i<=n; ++i)
        {
            scanf("%d",&x);
            tac^=x;
        }
        if (tac==0)
            printf("NU\n");
        else
            printf("DA\n");
    }
    return 0;
}*/
#include <cstdio>
using namespace std;
int main()
{
    int n,tac,x;
    scanf("%d",&n);
    tac=0;
    for(register int i=1; i<=n; ++i)
    {
        scanf("%d",&x);
        tac^=x;
    }
    if (tac==0)
        printf("NU EXISTA STRATEGIE\n");

    return 0;
}
