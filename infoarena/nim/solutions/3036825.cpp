#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t;
int n, x;
int suma;
int q, i;

int main()
{
    fin >>t;
    for (q = 1; q <= t; ++q)
    {
        fin >>n;
        fin >>suma;
        for (i = 2; i <= n; ++i)
        {
            fin >>x;
            suma ^= x;
        }

        if (!suma) fout <<"NU\n";
        else fout <<"DA\n";
    }
    fout.close();
    return 0;
}
