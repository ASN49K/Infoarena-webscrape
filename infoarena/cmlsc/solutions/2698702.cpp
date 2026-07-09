#include <fstream>
#define MAX 1030
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int A[MAX], B[MAX], M, N;
int sol[MAX];
int main()
{
    int k = 1, cj = 1;
    fin >> M >> N;
    for (int i = 1; i <= M; ++i)
        fin >> A[i];
    for (int i = 1; i <= N; ++i)
        fin >> B[i];

    int mare, mic;
    if (M > N)
        mare = M, mic = N;
    else
        mare = N, mic = M;
    
    for (int i = 1; i <= mare; ++i)
    {
        for (int j = cj; j <= mic; ++j)
        {
            if (mare == M && mic == N)
            {
                if (A[i] == B[j])
                    sol[k++] = A[i], cj = j + 1;
            }
            else
                if (B[i] == A[j])
                    sol[k++] = B[i], cj = j + 1;

        }
    }
    k--;
    fout << k << "\n";
    for (int i = 1; i <= k; ++i)
        fout << sol[i]<<" ";
}
