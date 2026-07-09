#include <fstream>

using namespace std;

int cmmdc( int a, int b ) {
    int r;
    while ( b != 0 ) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main() {
    ifstream fin( "euclid2.in" );
    ofstream fout( "euclid2.out" );
    int n, i, a, b, rez;
    fin >> n;
    for ( i = 0; i < n; i ++ ) {
        fin >> a >> b;
        rez = cmmdc( a, b );
        fout << rez << '\n';
    }
    return 0;
}