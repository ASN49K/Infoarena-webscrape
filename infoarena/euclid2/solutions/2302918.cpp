#include <fstream>

using namespace std;

int main( ) {

    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int nr_perechi;
    fin >> nr_perechi;

    int a[100000], b[100000], rest[100000];

    for(int i = 0; i < nr_perechi; i ++) {
        fin >> a[i] >> b[i];
        rest[i] = a[i] % b[i];
        while( rest[i] != 0 ) {
            a[i] = b[i];
            b[i] = rest[i];
            rest[i] = a[i] % b[i];
        }
        fout << b[i] << "\n";
    }
    return 0;
}
