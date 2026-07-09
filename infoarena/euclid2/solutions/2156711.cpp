#include <fstream>

using namespace std;

int gcd(int a, int b)
{
    if (!a)
        return b;
    return gcd(b%a, a);
}

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int n, a, b;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> a >> b;
        fout << gcd(a, b) << "\n";
    }
    return 0;
}
