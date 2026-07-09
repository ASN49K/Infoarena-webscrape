# include <cstdio>

const int N = 1024;

int a [N + 1] [N + 1];
int v [N + 1], u [N + 1], sir [N + 1];
int n, m, nrN;

int max2 (int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void init ()
{
    int i, j, bst = 0;

    freopen ("cmlsc.in", "r", stdin);
    freopen ("cmlsc.out", "w", stdout);

    scanf ("%d %d", & n, & m);

    for (i = 1; i <= n; i ++)
        scanf ("%d", & v [i]);

    for (i = 1; i <= m; i ++)
        scanf ("%d", & u [i]);

    for (i = 1; i <= n; i ++)
        for (j = 1; j <= m; j ++)
            if (v [i] == u [j])
                a [i] [j] = a [i - 1] [j - 1] + 1;
            else
                a [i] [j] = max2 (a [i - 1] [j], a [i] [j - 1]);

    i = n;
    j = m;

    while (i > 0)
        if (v [i] == u [j])
        {
            sir [++ bst] = v [i];
            i --;
            j --;
        }
        else if (a [i - 1] [j] < a [i] [j - 1])
            j --;
        else
            i --;

    printf ("%d\n", bst);

    for (i = bst; i > 0; i --)
        printf ("%d ", sir [i]);
}

int main ()
{
    init ();
}
