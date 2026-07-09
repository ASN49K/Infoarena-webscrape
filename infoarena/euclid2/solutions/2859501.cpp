#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int t;
    fin >> t;
    int a, b, r;
    for (int i = 1; i <= t; ++i) {
        fin >> a >> b;
        while (b != 0) {
            r = a % b;
            a = b;
            b = r;
        }
        fout << a << "\n";
    }
}
