#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int T, a, b, r, i;
    fin >> T;

    for (i = 0; i < T; ++i)
    {
        fin >> a;
        fin >> b;
        while (b)
        {
            r = a % b;
            a = b;
            b = r;
        }
        fout << a << '\n';
    }

    fin.close();
    fout.close();
    return 0;
}
