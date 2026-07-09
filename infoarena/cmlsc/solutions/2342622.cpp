#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMax = 1024;

int N, M, DP[NMax + 5][NMax + 5], A[NMax + 5], B[NMax + 5], Sol[NMax + 5], ct;

int main()
{
    fin >> N >> M;

    for(int i = 1; i <= N; i++) fin >> A[i];

    for(int j = 1; j <= M; j++) fin >> B[j];

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            DP[i][j] = max(DP[i - 1][j - 1] + (A[i] == B[j]), max(DP[i - 1][j], DP[i][j - 1]));

    for(int i = N, j = M; i && j;)
    {
        if(A[i] == B[j])
            Sol[++ct] = A[i], i--, j--;
        else
            (DP[i - 1][j] < DP[i][j - 1]) ? j-- : i--; ///aleg maximul
    }
    fout << DP[N][M] << '\n';

    while(ct)
        fout << Sol[ct--] << " ";

    fout << '\n';

    fin.close();
    fout.close();

    return 0;
}
