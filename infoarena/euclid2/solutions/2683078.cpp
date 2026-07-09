#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main() {
    long long T, a, b;
    fin >> T;
    while (T) {
        fin >> a >> b;
        if (a < b) {
            swap(a, b);
        }
        while (b != 0) {
            int rest = a % b;
            a = b;
            b = rest;
        }
        fout << a << "\n";
        --T;
    }
    return 0;
}
