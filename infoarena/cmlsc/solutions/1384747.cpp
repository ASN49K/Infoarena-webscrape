#include <fstream>

using namespace std;

struct Position{
    short x, y;
};

short A[1026];
short B[1026];
short subsirComun[1026][1026];
Position previous[1026][1026];

int main()
{
    FILE * fin = fopen("cmlsc.in", "r");
    FILE * fout= fopen("cmlsc.out", "w");

    int n, m, i, j, _i, k;
    fscanf(fin, "%d %d", &n, &m);
    for (i = 1; i <= n; ++i)
    {
        fscanf(fin, "%hd", &A[i]);
    }
    for (i = 1; i <= m; ++i)
    {
        fscanf(fin, "%hd", &B[i]);
    }

    for (i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j)
        {
            if (A[i] == B[j]) {
                subsirComun[i][j] = subsirComun[i-1][j-1] + 1;
                previous[i][j].x = i;
                previous[i][j].y = j;
            } else {
                if (subsirComun[i-1][j] > subsirComun[i][j-1]) {
                    subsirComun[i][j] = subsirComun[i-1][j];
                    previous[i][j].x = previous[i-1][j].x;
                    previous[i][j].y = previous[i-1][j].y;
                } else /*if (subsirComun[i-1][j] <= subsirComun[i][j-1])*/ {
                    subsirComun[i][j] = subsirComun[i][j-1];
                    previous[i][j].x = previous[i][j-1].x;
                    previous[i][j].y = previous[i][j-1].y;
                }
            }
        }

    fprintf(fout, "%hd\n", subsirComun[n][m]);
    i = n;
    j = m;
    k = 0;
    while (previous[i][j].x)
    {
        _i = i;
        i = previous[_i][j].x;
        j = previous[_i][j].y - 1;
        B[k++] = A[i--]; // reuse B as a stack
    }
    for (--k; k > 0; --k)
    {
        fprintf(fout, "%hd ", B[k]);
    }
    fprintf(fout, "%hd\n", B[0]);

    fclose(fin);
    fclose(fout);
    return 0;
}
