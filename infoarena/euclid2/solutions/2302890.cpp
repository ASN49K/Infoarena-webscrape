#include <fstream>

using namespace std;

int main( ) {

    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int a, b, rest;
    cin >> a >> b;

    rest = a % b;
    while( rest != 0 ) {
        a = b;
        b = rest;
        rest = a % b;
    }
    fout << b;

    return 0;
}
