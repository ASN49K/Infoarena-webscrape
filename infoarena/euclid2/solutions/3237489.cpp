#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int t, a, b;
    fin >> t;
    while (t-- > 0)
    {
        fin >> a >> b;
        fout << gcd(a, b) << "\n";
    }
    return 0;
}