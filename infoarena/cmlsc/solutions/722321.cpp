#include <cstdio>
#include <cstring>
#define NMAX 1024

using namespace std;

int n, m, l, a[NMAX], b[NMAX];
int d[NMAX][NMAX], v[NMAX];
void read () {
    scanf ("%d%d", &n, &m);
    int i;
    for (i=1; i<=n; ++i)
        scanf ("%d", &a[i]);
    for (i=1; i<=m; ++i)
        scanf("%d", &b[i]);
}

inline int maxim (int x, int y) {
    return x>y ? x : y;
}

void solve() {
    memset(d, 0, NMAX*NMAX*sizeof(int));
    int i, j;
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            if (a[i]==b[j])
                d[i][j] = d[i-1][j-1]+1;
            else
                d[i][j] = maxim(d[i-1][j], d[i][j-1]);

}

void construct () {
    int j, k;
    for (l=0,j=n,k=m; j; )
        if (a[j]==b[k]) {
            v[++l] = a[j];
            --k; --j;
        }
        else
            if (d[j-1][k] < d[j][k-1])
                --k;
            else
                --j;

}

void write () {
    printf("%d\n", l);
    for (int i=l; i>0; --i)
        printf("%d ",v[i]);
}

int main () {
    freopen("cmlsc.in", "r", stdin);
    read();
    fclose(stdin);
    solve();
    construct();
    freopen("cmlsc.out", "w", stdout);
    write();
    fclose(stdout);
    return 0;
}
