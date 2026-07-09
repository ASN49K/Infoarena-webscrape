#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b)
{
    if (b == 0)
        return a;
    return euclid(b, a % b);
}

int main()
{
    int nr, x, y;

    fin >> nr;
    for (int i = 0; i < nr; i++) {
        fin >> x >> y;
        fout << euclid(x, y) << '\n';
    }
    return 0;
}
