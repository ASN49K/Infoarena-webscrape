#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    unsigned long long T;
    fin >> T;

    for (int i = 1; i <= T; i++) {
        unsigned long long a, b;
        fin >> a >> b;

        while (a != b) {
            if (a > b) {
                a -= b;
            } else {
                b -= a;
            }
        }
        fout << a << endl;
    }
    return 0;
}