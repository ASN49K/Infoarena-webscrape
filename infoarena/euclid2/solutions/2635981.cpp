#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long t, a, b;

long euclid(int a, int b) {
    if(!b) return a;
    return euclid(b, a%b);
}

int main() {
    fin >> t;
    while(t--) {
        fin >> a >> b;
        fout << euclid(a, b) << '\n';
    }
}
