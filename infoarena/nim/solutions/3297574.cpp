#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin( "nim.in" );
    ofstream fout( "nim.out" );
    int t, n, x;
    fin >> t;
    while ( t-- ) {
        fin >> n;
        x = 0;
        for ( int i = 0, a; i < n; i ++ ) {
            fin >> a;
            x ^= a;
        }
        if ( x == 0 ) fout << "NU\n";
        else fout << "DA\n";
    }
    return 0;
}