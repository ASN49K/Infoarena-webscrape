#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");


int gcd(int a, int b) {
    if (!a) {
        return b;
    }
    return gcd(b % a, a);
}

int main() {
    int T, A, B;
    fin >> T;
    for (int i = 0; i < T; ++i) {
        fin >> A >> B;
        fout << gcd(A, B) << "\n";
    }

    return 0;
}