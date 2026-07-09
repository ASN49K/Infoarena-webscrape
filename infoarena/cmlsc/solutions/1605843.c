#include <stdio.h>
#include <stdlib.h>

#define IN "cmlsc.in"
#define OUT "cmlsc.out"
#define MAXN 1026

int d[MAXN + 1][MAXN + 1], a[MAXN + 1], b[MAXN + 1];

void read (int *n, int *m){
    int i;
    scanf ("%d%d", n, m);
    for (i = 1; i <= *n; ++ i)
        scanf ("%d", &a[i]);
    for (i = 1; i <= *m; ++ i)
        scanf ("%d", &b[i]);
}

void printSolution (int n, int m){
    int i, j, v[MAXN + 1], k = 0;

    for (j = m, i = n; j >= 1 && i >= 1;){
        if (a[i] == b[j])
            v[++k] = a[i];
        if (d[i - 1][j] > d[i][j - 1])
            -- i;
        else
            -- j;
    }

    for (i = k; i >= 1; -- i)
        printf ("%d ", v[i]);

    printf ("\n");
}

inline int max (int x, int y){
    if (x > y)
        return x;
    return y;
}

void best (int n, int m){
    int i, j;

    for (i = 1; i <= n; ++ i)
        for (j = 1; j <= m; ++j)
            if (a[i] == b[j])
                d[i][j] = 1 + d[i - 1][j - 1];
            else
                d[i][j] = max (d[i - 1][j], d[i][j -1]);

    printf ("%d\n", d[n][m]);
    printSolution (n, m);
}

int main(void){
    freopen (IN, "r", stdin);
    freopen (OUT, "w", stdout);

    int n1, n2;

    read (&n1, &n2);
    best(n1, n2);

    fclose (stdin);
    fclose (stdout);
    return 0;
}
