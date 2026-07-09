#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int a, b, T;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main()
{
    fin >> T;

    while (T--)
    {
        fin >> a >> b;
        fout << gcd(a, b) << '\n';
    }

    fin.close();
    fout.close();
    return 0;
}
