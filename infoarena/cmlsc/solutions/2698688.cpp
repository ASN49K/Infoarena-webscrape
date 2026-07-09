#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int A[1 << 10], B[1 << 10], M, N;
int sol[1 << 10], k, cj;
int main()
{
    fin >> M >> N;
    for (int i = 0; i < M; ++i)
        fin >> A[i];
    for (int i = 0; i < N; ++i)
        fin >> B[i];
    if (M > N)
    {
        for (int i = 0; i < M; ++i)
        {
            for (int j = cj; j < N; ++j)
            {
                if (A[i] == B[j])
                    sol[k++] = A[i], cj = j + 1;
            }
        }
    }
    else
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = cj; j < M; ++j)
            {
                if (B[i] == A[j])
                    sol[k++] = B[i], cj = j + 1;
            }
        }
    }
    fout << k << "\n";
    for (int i = 0; i < k; ++i)
        fout << sol[i]<<" ";
}
