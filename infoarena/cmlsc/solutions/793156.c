#include <stdio.h>
#include <assert.h>

#define LIM 1024
#define max(x, y) (((x) > (y)) ? (x) : (y)) 

void init(const char* input, const char* output)
{
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
}

void run()
{
    int x[LIM];
    int y[LIM];
    int c[LIM][LIM];
    int best[LIM];
    int cnt = 0;
    int m, n, i, j;
    
    scanf("%d", &m);
    scanf("%d", &n);
    for (i = 0; i < m; i++) scanf("%d", &x[i]);
    for (i = 0; i < n; i++) scanf("%d", &y[i]);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (x[i] == y[j]) {
                c[i][j] = ((i > 0 && j > 0) ? c[i - 1][j - 1] : 0) + 1;
            } else {
                c[i][j] = 0;
                if (i > 0) 
                    c[i][j] = max(c[i][j], c[i - 1][j]);
                if (j > 0) 
                    c[i][j] = max(c[i][j], c[i][j - 1]);
            }
        }
    }

    i = m - 1;
    j = n - 1;

    for (i = m - 1, j = n - 1; (i != -1 || j != -1); ) {
        if (x[i] == y[j]) {
            best[cnt++] = x[i];
            i--;
            j--;
        } else if (i > 0 && c[i - 1][j] == c[i][j]) {
            i--;
        } else if (j > 0 && c[i][j - 1] == c[i][j]) {
            j--;
        } else if (i || j) {
            assert(0);
        }
    }

    printf("%d\n", cnt);
    for (i = cnt - 1; i >= 0; i--) printf("%d ", best[i]);
}

int main()
{
    init("cmlsc.in", "cmlsc.out");
    run();
    return 0;
}
