#include <fstream>
using namespace std;

int main()
{
    int T, a, b, r;

    ifstream infile("euclid2.in");
    ofstream outfile("euclid2.out");

    infile >> T;
    for (;T > 0; T--)
    {
        infile >> a >> b;
        while (b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        outfile << a << "\n";
    }
}
