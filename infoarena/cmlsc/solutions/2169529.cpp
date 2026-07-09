#include <fstream>

using namespace std;

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int sir_a[1025], sir_b [1025], subsir[1025];
    int M, N, i, aj = 1, pos_subsir = 1, subsir_count = 0;
    fin>>M>>N;

    // Reads the elements of array_a.
    for (i = 1; i <= M; ++i)
        fin>>sir_a[i];

    // Reads the elements of array_b.
    for (i = 1; i <= N; ++i)
        fin>>sir_b[i];

    while (aj != N + 1)
    {
        for (i = 1; i <= M; ++i)
        {
            if (sir_a[i] == sir_b[aj])
            {
                subsir[pos_subsir] = sir_a[i];
                ++pos_subsir;
                subsir_count += 1;
                i = M;
            }
        }
        ++aj;
    }

    fout<<subsir_count<<endl;

    for (i = 1; i <= subsir_count; ++i)
        fout<<subsir[i]<<" ";
    return 0;
}
