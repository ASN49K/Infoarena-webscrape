# include <cstdio>
using namespace std;

FILE *f = freopen("euclid2.in", "r", stdin);
FILE *g = freopen("euclid2.out", "w", stdout);

const int T_MAX = 100001;
const int A_MAX = 2*1e9;

int t, a, b;

int cmmdc(int a, int b)
{
    int c;

    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

void read_and_solve()
{
    scanf("%d", &t);

    for (int i=1; i<=t; i++)
    {
        scanf("%d %d", &a, &b);

        printf("%d\n", cmmdc(a,b));
    }
}

int main()
{
    read_and_solve();
    return 0;
}
