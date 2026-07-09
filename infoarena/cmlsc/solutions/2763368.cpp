#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int M, N, A[1500], B[1500], i, j, best[1050][1050];

void afis(int M, int N) {
    if (best[M][N] == 0) return;
    if (A[M-1] == B[N-1])
    {
        afis(M-1, N-1);
        fout << A[M-1] << " ";
    }
    else if (best[M-1][N] > best[M][N-1]) afis(M - 1, N);
         else afis(M, N - 1);
}

int main()
{
    fin >> M >> N;
    for (i = 0; i < M; i++)
        fin >> A[i];
    for (i = 0; i < N; i++)
        fin >> B[i];
    // best[i][j] = result for A[0..i) and B[0..j)
    for (i = 0; i < M; i++)
        best[i][0] = 0;
    for (j = 0; j < N; j++)
        best[0][j] = 0;
    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
            if (A[i] == B[j]) best[i+1][j+1] = best[i][j] + 1;
            else best[i+1][j+1] = max(best[i+1][j], best[i][j+1]);
    fout << best[M][N] << endl;
    afis(M, N);
    return 0;
}
