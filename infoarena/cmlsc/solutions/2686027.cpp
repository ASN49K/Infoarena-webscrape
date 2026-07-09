#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    unsigned short A[1025], M; // A vector with M elements
    unsigned short B[1025], N; // B vector with N elements

    fin >> M >> N;
    for (int i = 0; i < M; ++i)
        fin >> A[i];

    for (int i = 0; i < N; ++i)
        fin >> B[i];

    unsigned short destination_vector[1025], P = 0;
    unsigned short current_vector[1025], Q = 0;

    for (int i = 0; i < M; ++i)
    {
        int piv = 0; // pivotul pentru j
        for (int i2 = i; i2 < M && piv < N; ++i2)
            for (int j = piv; j < N; ++j)
                if (A[i2] == B[j])
                {
                    current_vector[++Q] = B[j];
                    piv = j + 1;
                }

        if (Q > P)
        {
            P = Q;
            for (int j = 1; j <= P; ++j)
                destination_vector[j] = current_vector[j];
        }

        Q = 0;
    }

    fout << P << '\n';
    for (int i = 1; i <= P; ++i)
        fout << destination_vector[i] << ' ';

    return 0;
}
