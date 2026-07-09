#include <fstream>

using namespace std;

void Read ()
{
    ifstream fin ("nim.in");
    ofstream fout ("nim.out");
    int tests, n;
    fin >> tests;
    while (tests--)
    {
        int xorsum = 0, x;
        fin >> n;
        while (n--)
        {
            fin >> x;
            xorsum ^= x;
        }
        if (xorsum) fout << "DA\n";
        else fout << "NU\n";
    }
}


int main()
{
    Read();
    return 0;
}
