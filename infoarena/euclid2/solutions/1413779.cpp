#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T, a, b;

int Euclid(int a, int b)
{
    if (!b)
        return a;
    return Euclid(b, a % b);
}

int main()
{
    fin >> T;
    while (T--)
    {
        fin >> a >> b;
        fout << Euclid(a, b) << '\n';
    }

    fin.close();
    fout.close();
    return 0;
}
