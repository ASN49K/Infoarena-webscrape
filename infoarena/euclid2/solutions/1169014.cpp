#include <fstream>
#include <algorithm>

using namespace std;

int T;

int gcd(int a, int b)
{
    int rnow = 1;
    while (true)
    {
        if (a == 0)
        {
            rnow *= b;
            break;
        }
        if (b == 0)
        {
            rnow *= a;
            break;
        }
        if (!(a & 1) && !(b & 1))
        {
            rnow *= 2;
            a >>= 1;
            b >>= 1;
        }
        else if (!(a & 1))
            a >>= 1;
        else if (!(b & 1))
            b >>= 1;
        else
        {
            if (a >= b) a -= b;
            else        b -= a;
        }
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
