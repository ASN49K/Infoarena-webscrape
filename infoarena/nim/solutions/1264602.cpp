#include<fstream>

using namespace std;

ifstream fin( "nim.in" );
ofstream fout( "nim.out" );

int main() {
    int n, t, s, x;
    fin >> t;
    while ( t -- ) {
        fin >> n;
        s = 0;
        for( int i = 0; i < n; ++ i ) {
            fin >> x;
            s = s ^ x;
        }
        if ( s > 0 ) {
            fout << "DA\n";
        } else {
            fout << "NU\n";
        }
    }
    fin.close();
    fout.close();
    return 0;
}
