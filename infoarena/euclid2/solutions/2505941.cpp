#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int Cmmdc(int a, int b);

int main()
{
    int T;
    fin >> T;

    int x, y;
    for (int i = 0; i < T; ++i)
    {
        fin >> x >> y;
        fout << Cmmdc(x, y) << '\n';
    }

    fin.close();
    fout.close();
    return 0;
}

int Cmmdc(int a, int b)
{
    int c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}
