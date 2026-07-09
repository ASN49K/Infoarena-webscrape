#include <fstream>

using namespace std;

int n, a, b;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin >> n;
    for (int i = 1;i <= n;++i)
    {
        fin >> a >> b;
        fout << gcd(a, b) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
