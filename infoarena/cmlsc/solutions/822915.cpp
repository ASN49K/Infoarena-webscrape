#include<cstdio>

FILE* in;
FILE* out;

int max(int a, int b)
{
        return (a < b)?b:a;
}

int* solve(int** &M, int *x, int *y, int n, int m)
{
        M = new int*[m + 1];
        for(int i = 0; i < m + 1; ++i) {
                M[i] = new int[n + 1];
                M[i][0] = 0;
        }
        for(int j = 0; j < n + 1; ++j)
                M[0][j] = 0;

        for(int i = 1; i < m + 1; ++i) {
                for(int j = 1; j < n + 1; ++j) {
                        if(x[j] == y[i])
                                M[i][j] = j;
                        else
                                M[i][j] = max(M[i][j - 1], M[i - 1][j]);
                }
        }

        int *rez = new int[n];
        for(int i = 1; i < n + 1; ++i) {
                if(M[m][i - 1] != M[m][i])
                        rez[++rez[0]] = M[m][i];
        }

        fprintf(out, "%d\n", rez[0]);
        for(int i = 1; i <= rez[0]; ++i)
                fprintf(out, "%d ", x[rez[i]]);
        fprintf(out, "\n");
        return rez;
}

void afis(int **M, int n, int m)
{
        for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j)
                        fprintf(stderr, "%d ", M[i][j]);
                fprintf(stderr, "\n");
        }
}

int main()
{

        in = fopen("cmlsc.in", "r");
        out = fopen("cmlsc.out", "w");
        int n, m;
        int *x, *y;

        fscanf(in, "%d%d", &n, &m);

        x = new int[n + 1];
        y = new int[m + 1];

        for(int i = 0; i < n; ++i)
                fscanf(in, "%d", x + i + 1);
        for(int i = 0; i < m; ++i)
                fscanf(in, "%d", y + i + 1);


        int **M;
        int *rez;

        if(n > m)
                rez = solve(M, y, x, m, n);
        else
                rez = solve(M, x, y, n, m);

        delete rez;
        for(int i = 0; i < m + 1; ++i)
                delete M[i];
        delete M;

        return 0;
}
