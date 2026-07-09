#include <stdio.h>
#include <stdlib.h>

#define FILEIN "cmlsc.in"
#define FILEOUT "cmlsc.out"

int c[1025][1025], l;
char b[1025][1025];

void lcs_length(int x[], int y[], int m, int n)
{
        int i, j;

        for (i = 1; i <= m; i++)
                c[i][0] = 0;
        for (j = 1; j <= n; j++)
                c[0][j] = 0;
        for (i = 1; i <= m; i++)
                for (j = 1; j <= n; j++)
                        if (x[i - 1] == y[j - 1]) {
                                c[i][j] = c[i - 1][j - 1] + 1;
                                b[i][j] = 'd';
                        } else if (c[i - 1][j] >= c[i][j - 1]) {
                                        c[i][j] = c[i - 1][j];
                                        b[i][j] = 'u';
                        } else {
                                c[i][j] = c[i][j - 1];
                                b[i][j] = 'l';
                        }
}

void print_lcs(FILE *fileOut, int x[], int i, int j, int l)
{
        if (i == 0 || j == 0)
                return;
        if (b[i][j] == 'd') {
                print_lcs(fileOut, x, i - 1, j - 1, l);
                fprintf(fileOut, "%d ", x[i - 1]);
                ++l;
        } else if (b[i][j] == 'u')
                        print_lcs(fileOut, x, i - 1, j, l);
               else
                        print_lcs(fileOut, x, i, j - 1, l);
}

int main (int argc, char* argv[])
{
        FILE *fileIn, *fileOut;
        int x[1024], y[1024], m, n, i;

        fileIn = fopen(FILEIN, "r");
        fileOut = fopen(FILEOUT, "w");
        if (fileIn == NULL) {
            printf("cannot open file %s\n", FILEIN);
            exit(1);
        }
        fscanf(fileIn, "%d %d", &m, &n);
        for (i = 0; i < m; ++i)
            fscanf(fileIn, "%d", &x[i]);
        for (i = 0; i < n; ++i)
            fscanf(fileIn, "%d", &y[i]);

        lcs_length(x, y, m, n);
        fprintf(fileOut, "%d\n", c[m][n]);
        print_lcs(fileOut, x, m, n, l);
        
        return 0;
}
