#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main() {
    int numberOfPairs;
    fin >> numberOfPairs;
    for (int pair = 1; pair <= numberOfPairs; ++pair) {
        int a, b;
        fin >> a >> b;
        while (b > 0) {
            int rest = a % b;
            a = b;
            b = rest;
        }
        fout << a << '\n';
    }
    return 0;
}
