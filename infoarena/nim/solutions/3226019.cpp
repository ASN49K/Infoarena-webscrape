#include <iostream>
#include <fstream>
#define nl '\n'

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
    int T, N, x, S;
    fin >> T;
    while (T--)
    {
        fin >> N;
        S = 0;
        while (N--)
        {
            fin >> x;
            S^=x;
        }
        fout << (S != 0 ? "DA\n" : "NU\n");
    }
    fin.close();
    fout.close();
    return 0;
}

