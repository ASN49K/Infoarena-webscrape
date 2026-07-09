#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main(void)
{
    int M, N, i, j, k, maxs;
    f >> M >> N;
    int A[M], B[N], C[max(M,N)];
    int D[M][N];
    for (i=0; i<M; i++)
        f >> A[i];
    for (j=0; j<N; j++)
        f >> B[j];

    for (i=0; i<M; i++)
    {
        D[i][0] = 0;
        for (k=0; k<=i; k++)
            if (B[0]==A[k])
            {
                D[i][0] = 1;
                break;
            }
    }

    for (j=0; j<N; j++)
        for (k=0; k<=j; k++)
        {
            D[0][j] = 0;
            if (A[0]==B[k])
            {
                D[0][j] = 1;
                break;
            }
        }
    for (i=1; i<M; i++)
    {
        for (j=1; j<N; j++)
        {
            if (A[i]!=B[j])
            {
                D[i][j] = max(D[i-1][j],D[i][j-1]);
            }
            else
            {
                D[i][j] = D[i-1][j-1] + 1;
            }
        }
    }
    g << D[M-1][N-1];
    g << '\n';
    maxs = D[M-1][N-1];
    i = M-1;
    j = N-1;
    while (maxs > 0)
    {
        if (D[i][j] == maxs)
        {
            if (D[i-1][j]<maxs&&D[i][j-1]<maxs)
            {
                C[maxs] = A[i];
                maxs--;
                i--;
                j--;
            }
            else if (i>0)
                i--;
            else
            {
                i = M-1;
                j--;
            }
        }
        else if (i>0)
            i--;
        else
        {
            i = M-1;
            j--;
        }
    }
    for (i=1; i<=D[M-1][N-1]; i++)
        g << C[i] << ' ';
    return 0;
}
