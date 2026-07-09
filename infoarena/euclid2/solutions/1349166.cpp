#include <fstream>

int gcd(int a, int b)
{
    return !b ? a : gcd(b, a%b);
}

int main()
{
    std::ifstream fin("euclid2.in");
    std::ofstream fout("euclid2.out");

    int T;
    fin >> T;
    for (; T; --T) {
        int a, b;
        fin >> a >> b;

        fout << gcd(a, b) << "\n";
    }

    return 0;
}
