#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd( int x, int y ) {
    if ( y>0 ) {
        return gcd(y, x%y);
    }
    return x;
}

int main() {
    int t;
    fin>>t;

    for ( int i= 0, a, b; i<t; ++i ) {
        fin>>a>>b;

        fout<<gcd(a, b)<<"\n";
    }

    return 0;
}
