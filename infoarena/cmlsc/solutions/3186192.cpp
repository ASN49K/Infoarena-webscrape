#include <fstream>

using namespace std;
const int NMAX = 1025;

int N, M, A[NMAX], B[NMAX], DP[NMAX][NMAX], S[NMAX], k;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

void citire()
{
    f >> N >> M;
    for (int i = 1; i <= N; i++)
        f >> A[i];
    for (int i = 1; i <= M; i++)
        f >> B[i];
}

void dinamica()
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if(A[i] == B[j])
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else
                DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
}

void reconstituire()
{
    int i = N, j = M;
    while(i > 0 && j > 0)
    {
        if(A[i] == B[j])
        {
            S[++k] = A[i];
            i--;
            j--;
        }
        else
            if(DP[i - 1][j] > DP[i][j - 1])
            i--;
        else
            j--;
    }
}

int main()
{
    citire();
    dinamica();
    g << DP[N][M] << '\n';
    reconstituire();
    for (int i = k; i >= 1; i--)
        g << S[i] << ' ';
    f.close();
    g.close();
    return 0;
}