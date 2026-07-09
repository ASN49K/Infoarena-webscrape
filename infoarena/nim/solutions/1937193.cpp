#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t, n, x, y;

int main()
{
    fin >> t;
    while ( t )
    {
        t--;
        fin >> n;
        fin >> x;
        for ( int i = 1; i < n; i++ )
        {
            fin >> y;
            x ^= y;
        }
        if ( x == 0 )
            fout << "NU" << '\n';
        else
            fout << "DA" << '\n';

    }
    fin.close();
    fout.close();
    return 0;
}
