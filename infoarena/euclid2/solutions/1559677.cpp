#include <fstream>

using namespace std;

int T;
long a, b;

int gcd(long a, long b)
{
    return !b ? a : gcd(b, a % b);
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    fin >> T;
    while(T)
    {
        fin >> a >> b;
        fout << gcd(a, b) << "\n";
        --T;
    }

    fin.close();
    fout.close();
    return 0;
}
