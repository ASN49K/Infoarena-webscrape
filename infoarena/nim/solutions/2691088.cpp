#include <fstream>
using namespace std;
ifstream fin ( "nim.in" );
ofstream fout ( "nim.out" );
int main () {
    int t, n, nr, x;
    fin >> t;
    while ( t-- ) {
        fin >> n;
        x = 0;
        for ( int i = 0; i < n; i++ ) {
            fin >> nr;
            x ^= nr;
        }
        fout << ( x == 0? "NU" : "DA" ) << '\n';
    }
    return 0;
}
