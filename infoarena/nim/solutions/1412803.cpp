#include <cstdio>

using namespace std;

bool nim()
{
    int N,x = 0,v;
    scanf("%d",&N);
    for(int i = 1; i <= N; ++i)
    {
        scanf("%d",&v);
        x ^= v;
    }
    return x != 0;
}

int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);

    int T;
    scanf("%d",&T);
    while(T--)
        if(nim())
            printf("DA\n");
        else
            printf("NU\n");

    return 0;
}
