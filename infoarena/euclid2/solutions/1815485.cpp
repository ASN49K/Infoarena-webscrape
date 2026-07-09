# include <cstdio>
using namespace std;

FILE *f = freopen("euclid2.in", "r", stdin);
FILE *g = freopen("euclid2.out", "w", stdout);

const int N_MAX = 100010;

int n;

void solve(int a, int b)
{
    int c;

    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }

    printf("%d\n", a);
}

void read()
{
    scanf("%d", &n);

    for (int i=1; i<=n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        solve(x, y);
    }
}

int main()
{
    read();
    return 0;
}
