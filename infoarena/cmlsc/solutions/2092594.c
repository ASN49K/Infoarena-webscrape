#include <stdio.h>

int A[1026][1026];

int main()
{
    FILE *in = fopen("cmlsc.in", "r");
    FILE *out;
    int n, m, a[1025], b[1025], sol[1025], index;

    /* read input */
    fscanf(in, "%d", &n);
    fscanf(in, "%d", &m);
    for (int i = 0; i < n; i++)
        fscanf(in, "%d", &a[i]);
    for (int i = 0; i < m; i++)
        fscanf(in, "%d", &b[i]);

    /* compute solution */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                A[i+1][j+1] = 1 + A[i][j];
            }
            else {
                A[i+1][j+1] = (A[i+1][j] > A[i][j+1] ? A[i+1][j] : A[i][j+1]);
            }
        }
    }

    /* compute the subsequence */
    int i = n, j = m;
    while(1) {
        if (a[i-1] == b[j-1]) {
            sol[index++] = a[i-1];
            i--;
            j--;
        } else {
            A[i-1][j] > A[i][j-1] ? i-- : j--;
        }

        if (i == 0 || j == 0)
            break;
    }

    /* print the output */
    out = fopen("cmlsc.out", "w");
    fprintf(out, "%d\n", A[n][m]);
    for (int i = index - 1; i >= 0; i--)
        fprintf(out, "%d ", sol[i]);

    fclose(in);
    fclose(out);

    return 0;
}