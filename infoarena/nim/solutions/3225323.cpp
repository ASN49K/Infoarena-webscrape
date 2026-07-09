#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main() {
    int test;
    fin>>test;
    for ( int i= 0; i<test; ++i ) {
        int n, sol= 0;
        fin>>n;
        for ( int j= 0, x; j<n; ++j ) {
            fin>>x;
            sol^= x;
        }

        if ( sol==0 ) {
            fout<<"NU\n";
        } else {
            fout<<"DA\n";
        }
    }

    return 0;
}
