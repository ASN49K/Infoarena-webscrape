#include <fstream>
using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

int t, n, x;

int xorNr;

int main()
{
    in >> t;
    while(t--)
    {
        xorNr = 0;

        in >> n;
        for(int i = 1; i <= n; i++)
        {
            in >> x;
            xorNr ^= x;
        }

        out << (xorNr ? "DA" : "NU") << '\n';
    }

    return 0;
}
