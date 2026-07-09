# include <cstdio>
using namespace std;
FILE *f = freopen("nim.in", "r", stdin);
FILE *g = freopen("nim.out", "w", stdout);

int n;

int main()
{
    scanf("%d", &n);

    int s;

    for (int i=1; i<=n; i++)
    {
        int t;

        scanf("%d", &t);

        s = 0;
        for (int j=1; j<=t; j++)
        {
            int x;
            scanf("%d", &x);
            s ^= x;
        }

        if (s == 0) printf("NU\n");
        else printf("DA\n");
    }
    return 0;
}
