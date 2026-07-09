#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    short int A[1025]; // A -> primul sir, de lungime M
    short int M;

    short int B; // B -> fiecare caracter din al doilea sir, sir de lungime N
    short int N;

    short int AP[257] = {0}; // vector de aparitii

    fin >> M >> N;
    for (int i = 0; i < M; ++i)
        fin >> A[i];

    short int P = 0;
    short int C[1025]; // C -> subsirul celor 2 siruri, de lungime P

    for (int i = 0; i < N; ++i)
    {
        fin >> B;

        for (int j = 0; j < M; ++j)
        {
            if (A[j] == B && AP[B] == 0)
            {
                AP[B]++;
                C[++P] = B;
            }
        }
    }

    fout << P << '\n';
    for (int i = 1; i <= P; ++i)
        fout << C[i] << " ";

    return 0;
}
