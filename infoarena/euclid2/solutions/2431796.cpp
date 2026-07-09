#include <iostream>
#include <fstream>
using namespace std;


int gcd(int a, int b) {
    if (!a) {
        return b;
    }
    return gcd(b % a, a);
}

int main() {
    int T, A, B;
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    fin >> T;
    for (int i = 0; i < T; ++i) {
        fin >> A >> B;
        fout << gcd(A, B) << endl;
    }

    return 0;
}