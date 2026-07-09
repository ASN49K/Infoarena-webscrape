#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

typedef long long i64;

i64 gcd( i64 x, i64 y ) {
    if ( y==0 ) {
        return x;
    }
    return gcd( y, x%y );
}

int main(  ) {
    int t;
    fin>>t;
    for ( int cnt= 1; cnt<=t; ++cnt ) {
        i64 x, y;
        fin>>x>>y;

        fout<<gcd(x, y)<<"\n";
    }

    return 0;
}
