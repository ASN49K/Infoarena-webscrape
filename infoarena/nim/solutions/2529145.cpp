#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin( "nim.in" );
    ofstream fout( "nim.out" );
    int t, n, i, j, rez, a;
    fin >> t;
    for ( j = 0; j < t; j ++ ) {
        fin >> n >> rez;
        for ( i = 1; i < n; i ++ ) {
            fin >> a;
            rez = a^rez;
        }
        if ( rez != 0 )
            fout << "DA" << '\n';
        else
            fout << "NU" << '\n';
    }
    return 0;
}
