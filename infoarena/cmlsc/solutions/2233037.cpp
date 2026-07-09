#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

unsigned mat[1025][1025];

int main()
{
    unsigned A[1025], B[1025], M, N, i, j, sol[1025], k = 0;
    f >> M >> N;
    for (i = 1; i <= M; i++)
        f >> A[i];
    for (j = 1; j <= N; j++)
        f >> B[j];
    f.close();
    for (i = 0; i <= M; i++)
        mat[i][0] = 0;
    for (j = 1; j <= N; j++)
        mat[0][j] = 0;
    for (i = 1; i <= M; i++)
        for (j = 1; j <= N; j++)
            if (A[i] == B[j])
                mat[i][j] = mat[i-1][j-1] + 1;
                else
                    mat[i][j] = max(mat[i][j-1], mat[i-1][j]);
    i = M;
    j = N;
    while (i && j)
        if (A[i] == B[j])
        {
            sol[++k] = A[i];
            i--;
            j--;
        }
            else
                if (mat[i-1][j] > mat[i][j-1])
                    i--;
                    else
                        j--;
    g << mat[M][N] << endl;
    for (i = k; i; i--)
        g << sol[i] << ' ';
    g.close();
    return 0;
}
