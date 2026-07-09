#include <fstream>
#define NMmax 1024

using namespace std;

int A[NMmax], B[NMmax], D[NMmax][NMmax], subsir[NMmax], M, N, k;

int maxim (int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{
    ifstream f ("cmlsc.in");
    ofstream g ("cmlsc.out");

    f >> M >> N;

    int i, j;

    for (i = 1; i <= M; i++)
        f >> A[i];
    for (i = 1; i <= N; i++)
        f >> B[i];

    for (i = 1; i <= M; i++)
        for (j = 1; j <= N; j++)
            if (A[i] == B[j])
                D[i][j] = 1 + D[i - 1][j - 1];
            else
                D[i][j] = maxim (D[i - 1][j], D[i][j - 1]);

    for (i = M, j = N; i; )
        if (A[i] == B[j])
        {
            subsir[k++] = A[i]; i--; j--;
        }
        else if (D[i - 1][j] < D[i][j - 1])
            j--;
        else
            i--;

    g << k << "\n";
    for (int i = k; i; i--)
        g << subsir[i] << " ";
    return 0;
}
