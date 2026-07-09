#include <fstream>
using namespace std;

int gcd(int a, int b) {
    if(!b)
        return a;
    return gcd(b, a % b);
}

ifstream fin("euclid.in");
ofstream fout("euclid.out");

int main() {
    int a, b, T;
    fin >> T;

    for(int t = 0; t < T; ++t) {
        fin >> a >> b;
        fout << gcd(a, b);
    }
}
