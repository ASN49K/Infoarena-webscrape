#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int T;

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    fin >> T;
    while (T--)
    {
        int A, B;
        fin >> A >> B;
        fout << gcd(A, B) << '\n';
    }

    fin.close();
    fout.close();
}
