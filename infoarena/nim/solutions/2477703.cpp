#include <bits/stdc++.h>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
    int n, x, rez,t;
    fin >> t;
    for (int j = 1; j <= t; j++)
    {
        fin>> n >> rez;
        for ( int i = 2; i <=n ; i++)
        {
            fin >> x;

            rez ^= x;
        }

        if ( rez == 0 )
            fout << "NU" << '\n';
        else fout << "DA" << '\n';
    }

}
