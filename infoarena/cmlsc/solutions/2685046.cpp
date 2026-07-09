#include <fstream>
using namespace std;

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int A[1025];
    int M, N;

    fin >> M >> N;

    for (int i = 1; i <= M; ++i)
        fin >> A[i];

    int B, cnt = 0;
    int C[1025], k = 0;
    for (int i = 1; i <= N; ++i)
    {
        fin >> B;

        int ap = 0;
        for (int j = 1; j <= M; ++j)
            if (A[j] == B)
                if (ap == 0)
                {
                    C[++k] = A[j];
                    cnt++;
                    ap++;
                }
                else
                    break;
    }

    fout << cnt << '\n';

    for (int i = 1; i <= k; ++i)
        fout << C[i] << ' ';

    return 0;
}
