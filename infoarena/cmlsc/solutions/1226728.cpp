#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int N, M;
int sir[1050], lg;
int A[1050], B[1050], DP[1050][1050];

void cmlsc()
{
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
        {
            if (A[i] == B[j]) DP[i][j] = 1 + DP[i - 1][j - 1];
            else              DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
        }
    fout << DP[N][M] << '\n';

    int x = N, y = M;
    while (true)
    {
        if (A[x] == B[y])
        {
            sir[++lg] = A[x];
            --x;
            --y;
            if (!DP[x][y]) break;
        }
        else if (DP[x - 1][y] < DP[x][y - 1])
            --y;
        else
            --x;
    }

    for (int i = lg; i >= 1; --i)
        fout << sir[i] << ' ';
    fout << '\n';
}

int main()
{
    fin >> N >> M;
    for (int i = 1; i <= N; ++i)
        fin >> A[i];
    for (int i = 1; i <= M; ++i)
        fin >> B[i];

    cmlsc();

    fin.close();
    fout.close();
    return 0;
}
