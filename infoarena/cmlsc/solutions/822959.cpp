#include<cstdio>

FILE* in;
FILE* out;
int *x, *y;
int n, m;

int **M;

int max(int a, int b)
{
        return (a < b)?b:a;
}

int swap(int &a, int &b)
{
        int aux = a;
        a = b;
        b = aux;
}

void traceback(int *rez, int imax, int jmax)
{
        for(int i = imax, j = jmax; i && j;) {
                if(x[j] == y[i]) {
                        rez[++rez[0]] = x[j];
                        i--;
                        j--;
                }
                else if(M[i - 1][j] > M[i][j - 1]) {
                        i--;
                }
                else {
                        j--;
                }
        }
}

void solve()
{
        int imax = 0, jmax = 0;
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
                                M[i][j] = M[i - 1][j - 1] + 1;
                        else
                                M[i][j] = max(M[i][j - 1], M[i - 1][j]);

                        if(M[i][j] > M[imax][jmax]) {
                                imax = i;
                                jmax = j;
                        }
                }
        }
        int *rez = new int[n];
        traceback(rez, imax, jmax);
        fprintf(out, "%d\n", rez[0]);
        for(int i = rez[0]; i > 0; --i)
                fprintf(out, "%d ", rez[i]);
        fprintf(out, "\n");

}

void afis(int **M)
{
        for(int i = 0; i < m + 1; ++i) {
                for(int j = 0; j < n + 1; ++j)
                        fprintf(stderr, "%3d ", M[i][j]);
                fprintf(stderr, "\n");
        }
}

int main()
{

        in = fopen("cmlsc.in", "r");
        out = fopen("cmlsc.out", "w");

        fscanf(in, "%d%d", &n, &m);

        if(n > m) {
                x = new int[n + 1];
                y = new int[m + 1];
                for(int i = 0; i < n; ++i)
                        fscanf(in, "%d", x + i + 1);
                for(int i = 0; i < m; ++i)
                        fscanf(in, "%d", y + i + 1);
        }
        else {
                int aux = n;
                n = m;
                m = aux;
                x = new int[n + 1];
                y = new int[m + 1];
                for(int i = 0; i < m; ++i)
                        fscanf(in, "%d", y + i + 1);
                for(int i = 0; i < n; ++i)
                        fscanf(in, "%d", x + i + 1);
        }

        solve();



        for(int i = 0; i < m + 1; ++i)
                delete M[i];
        delete M;

        return 0;
}
