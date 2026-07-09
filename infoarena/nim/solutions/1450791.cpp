#include <fstream>

using namespace std;

int main()
{
    int i, j, T, n, x, rez;
    ifstream fin("nim.in");
    ofstream fout("nim.out");

    fin >> T;
    for (i = 1; i <= T; ++i)
    {
        fin >> n;
        rez = 0;
        for (j = 1; j <= n; ++j)
        {
            fin >> x;
            rez ^= x;
        }
        if (rez == 0) fout << "NU\n";
        else fout << "DA\n";
    }

    fin.close();
    fout.close();
    return 0;
}
