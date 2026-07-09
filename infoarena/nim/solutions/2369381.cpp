#include <fstream>
#include <iostream>
#include <bitset>
using namespace std;

ifstream fin ("nim.in");
ofstream fout ("nim.out");

typedef long long ll;
int n, t;

void Solve ()
{
    fin >> t;
    while (t--)
    {
        int xors = 0;
        fin >> n;
        for (int i = 1; i <= n; i++)
        {
            int x;
            fin >> x;
            xors ^= x;
        }
        if (!xors)
            fout << "NU\n";
        else fout << "DA\n";
    }
    fout.close();
}

int main()
{
    Solve();
    return 0;
}
