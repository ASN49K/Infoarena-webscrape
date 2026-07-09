# include <cstdio>

using namespace std;

int t,n,suma_xor,s;

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    scanf("%d\n", &t);
    for(int test=1; test<=t; ++test)
    {
        scanf("%d\n", &n);
        suma_xor=0;
        for(int i=1; i<=n; ++i)
            scanf("%d ", &s), suma_xor^=s;

        if(suma_xor) printf("DA\n");
        else printf("NU\n");
    }
}
