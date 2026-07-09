#include <fstream>

template <typename T>
T cmmdc(T a, T b)
{
    while (b != 0) {
        long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    std::ifstream fin("euclid2.in");
    std::ofstream fout("euclid2.out");

    int t;
    fin >> t;

    while (t-- > 0) {
        long a, b;
        fin >> a >> b;
        fout << cmmdc(a, b) << '\n';
    }

    return 0;
}
