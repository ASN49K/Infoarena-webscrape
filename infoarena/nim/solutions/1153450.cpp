#include <cstdio>

using namespace std;
int N;

void read()
{
    scanf("%d",&N);
}

void solve()
{
    int _new, sumaxor = 0;
    for(int i = 1; i <= N; ++i)
    {
        scanf("%d",&_new);
        sumaxor ^= _new;
    }
    if(sumaxor) printf("DA\n");
    else printf("NU\n");
}

int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);

    int T;
    scanf("%d",&T);
    while(T--)
    {
        read();
        solve();
    }

    return 0;
}
