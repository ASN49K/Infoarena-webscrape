#include <fstream>

using namespace std;

int main()
{
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");

    long long T, a, b, i, rest;
    fin>>T;
    for (i = 1; i <= T; ++i)
    {
        fin >> a >> b;

        while (b != 0)
        {
            rest = a % b;
            a = b;
            b = rest;
        }
        fout << a << "\n";
    }
    return 0;
}
