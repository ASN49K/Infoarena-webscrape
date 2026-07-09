#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in"); // deschidem fisier
ofstream fout("euclid2.out"); // inchidem fisier

int main()
{
    int x,m,n;
    fin >> x;
    for( int i = 1; i <= x; i++){
         fin >> n >> m;

    while ( m != 0) {
        int r = n % m;
        n = m;
        m = r;

    }
    fout << n << endl;
    }

    return 0;
}
