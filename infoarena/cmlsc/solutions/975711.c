#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) ((a > b) ? a : b)

int main() {
    FILE *f = fopen("cmlsc.in","r");
    FILE *g = fopen("cmlsc.out","w");

    int n, m;
    int i, j, l;
    int *a, *b;
    int **lcs, *p;

    fscanf(f,"%d %d", &m, &n);
    a = malloc(m * sizeof(int));
    b = malloc(n * sizeof(int));

    lcs = calloc((m + 1), sizeof(int*));

    for (i = 0; i <= m; i++) {
        lcs[i] = calloc((n + 1), sizeof(int));
    }

    for (i = 0; i < m; i++) {
        fscanf(f,"%d", &a[i]);
    }

    for (i = 0; i < n; i++) {
        fscanf(f,"%d", &b[i]);
    }

    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            if (a[i-1] == b[j-1]) {
                lcs[i][j] = lcs[i-1][j-1] + 1;
            } else {
                lcs[i][j] = MAX(lcs[i][j-1], lcs[i-1][j]);
            }

    l = 0;
    p = malloc((lcs[m][n] + 1) * sizeof(int));
    for (i = m, j = n; i; ) {
        if (a[i - 1] == b[j - 1])
        {
            p[++l] = a[i - 1];
            i--;
            j--;
        }
        else {
            if (lcs[i-1][j] < lcs[i][j-1])
                j--;
            else 
                i--;
        }
    }
    
    fprintf(g, "%d\n", l);
    for (i = l; i; --i)
        fprintf(g, "%d ", p[i]);

    fclose(f);
    fclose(g);
    free(a);
    free(b);

    return 0;
}


