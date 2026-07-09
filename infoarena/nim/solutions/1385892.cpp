#include <fstream>
using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");

int main()
{
    int teste, i, n, xorsum, x;

    for(in >> teste; teste > 0; --teste)
    {
        in >> n; xorsum = 0;
        for(i = 1; i <= n; ++i)
        {
            in >> x;
            xorsum ^= x;
        }

        if( xorsum )
            out << "DA\n";
        else
            out << "NU\n";
    }
    return 0;
}
