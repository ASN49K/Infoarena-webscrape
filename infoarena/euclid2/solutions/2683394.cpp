#include <fstream>
std::ifstream fin("euclid2.in");std::ofstream fout("euclid2.out");
long long unsigned a, b, t;
int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}
int main()
{
    fin >> t;
    while (t--)
    {
        fin >> a >> b;
        fout << gcd(a, b) << std::endl;
    }
    fin.close(); fout.close();
    return 0;
}