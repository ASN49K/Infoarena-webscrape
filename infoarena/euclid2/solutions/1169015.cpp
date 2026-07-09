#include <fstream>
#include <algorithm>

using namespace std;

int T;

int gcd(int a, int b)
{
    int rnow = 1;
    while (!(a & 1) && !(b & 1))
    {
        rnow <<= 1;
        a >>= 1;
        b >>= 1;
    }
    while (!(a & 1)) // a is odd
        a >>= 1;

    while (true)
    {
        if (b == 0)
        {
            rnow *= a;
            break;
        }
        while (!(b & 1))
            b >>= 1;
        if (a > b)
            swap(a, b);
        b -= a;
    }

    return rnow;
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    fin >> T;

    int A, B;
    while (T--)
    {
        fin >> A >> B;
        fout << gcd(A, B) << '\n';
    }

    fin.close();
    fout.close();
}
