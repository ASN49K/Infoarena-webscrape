#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int T, i, a, b, r;
    fin >> T;
    for (i = 1; i <= T; i++)
    {
        fin >> a >> b;
        if (!b) fout << a;
        else
        {
            while (b)
            {
                r = a % b;
                a = b;
                b = r;
            }
            fout << a << "\n";
        }
    }

    return 0;
}
