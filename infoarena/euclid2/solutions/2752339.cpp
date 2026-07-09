#include <iostream>
#include <fstream>

using namespace std;
int T, a, b;
fstream fin, fout;

int gcd(int a, int b) {
    if(!b) return a;
    return gcd(b, a%b);
}

int main() {
    fin.open("euclid2.in", ios::in);
    fout.open("euclid2.out", ios::out);

    fin >> T;
    while(T--) {
        fin >> a >> b;
        fout << gcd(a, b) << '\n';
    }

    fin.close();
    fout.close();
}
