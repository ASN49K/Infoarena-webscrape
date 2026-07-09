#include <cstdio>

const int maxn = 1025;

FILE *in = fopen("cmlsc.in","r"), *out = fopen("cmlsc.out","w");

int n, m, a[maxn], b[maxn];

int sol[maxn][maxn];

void read()
{
    fscanf(in, "%d %d", &n, &m);

    for ( int i = 1; i <= n; ++i )
        fscanf(in, "%d", &a[i]);
    for ( int i = 1; i <= m; ++i )
        fscanf(in, "%d", &b[i]);
}

int max(int x, int y)
{
    return x > y ? x : y;
}

void go()
{
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            if ( a[i] == b[j] )
                sol[i][j] = sol[i-1][j-1] + 1;
            else
                sol[i][j] = max(sol[i-1][j], sol[i][j-1]);
}

void back(int x, int y)
{
    if ( !x || !y )
        return;

    if ( a[x] == b[y] )
    {
        back(x-1, y-1);
        fprintf(out, "%d ", a[x]);
    }
    else if ( sol[x][y-1] > sol[x-1][y] )
        back(x, y-1);
    else
        back(x-1, y);
}

int main()
{
    read();
    go();

    fprintf(out, "%d\n", sol[n][m]);

    back(n, m);

	return 0;
}
