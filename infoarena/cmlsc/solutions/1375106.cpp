#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int N, M;
int A[1050], B[1050];
int D[1050][1050], Ti[1050][1050], Tj[1050][1050];

void track(int i, int j)
{
    if (i == 0 && j == 0) return;

    track(Ti[i][j], Tj[i][j]);

    if (A[i] == B[j])
        fout << A[i] << ' ';
}

int main()
{
    fin >> N >> M;
    for (int i = 1; i <= N; ++i)
        fin >> A[i];
    for (int i = 1; i <= M; ++i)
        fin >> B[i];

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            if (A[i] == B[j])
            {
                D[i][j] = D[i - 1][j - 1] + 1;
                Ti[i][j] = i - 1;
                Tj[i][j] = j - 1;
            }
            else if (D[i - 1][j] > D[i][j - 1])
            {
                D[i][j] = D[i - 1][j];
                Ti[i][j] = i - 1;
                Tj[i][j] = j;
            }
            else
            {
                D[i][j] = D[i][j - 1];
                Ti[i][j] = i;
                Tj[i][j] = j - 1;
            }

    fout << D[N][M] << '\n';
    track(N, M);

    fin.close();
    fout.close();
}
