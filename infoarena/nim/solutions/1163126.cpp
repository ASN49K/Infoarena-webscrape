#include <cstdio>

using namespace std;

int main()
{
    int T,N,s,x,i;
    freopen ("nim.in","r",stdin);
    freopen ("nim.out","w",stdout);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        for(s=0,i=1;i<=N;++i)
        {
            scanf("%d", &x);
            s^=x;
        }
        if(!s)
            printf("NU\n");
        else
            printf("DA\n");
    }
    return 0;
}
