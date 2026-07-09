#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int v1[1025], v2[1025], N, M, d[1025][1025], sol[1025];

void lcs(int v1[1025], int n, int v2[1025], int m)
{
    for (int i = 0; i <= n; i++)
        d[i][0] = 0;

    for (int j = 0; j <= m; j++)
        d[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (v1[i] == v2[j])
                d[i][j] = d[i - 1][j - 1] + 1;
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }
    }
}

int main()
{
    FILE *in = fopen("cmlsc.in", "r");
    FILE *out = fopen("cmlsc.out", "w");

    fscanf(in, "%d", &N);
    fscanf(in, "%d", &M);
    for (int i = 1; i <= N; i++)
        fscanf(in, "%d", &v1[i]);

    for (int i = 1; i <= M; i++)
        fscanf(in, "%d", &v2[i]);

    lcs(v1, N, v2, M);

    int i = N, j = M, k = d[N][M];
    while (i > 0 && j > 0)
    {
        if (d[i][j] == d[i - 1][j - 1] + 1 && v1[i] == v2[j])
        {
            sol[k] = v1[i]; i--; j--; k--;
        }
        else
        {
            if (d[i - 1][j] > d[i][j - 1])
                i--;
            else
                j--;
        }
    }

    cout<<d[N][M]<<endl;
    fprintf(out, "%d\n", d[N][M]);
    for (int i = 1; i <= d[N][M]; i++)
    {
        fprintf(out, "%d ", sol[i]);
        cout<<sol[i]<<" ";
    }

    fclose(in);
    fclose(out);

    return 0;
}

