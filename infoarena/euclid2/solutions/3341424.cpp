#include <fstream>
#include <algorithm>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    if(b == 0) {
        return a;
    }
    
    int shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    
    do {
        b >>= __builtin_ctz(b);
        if(a > b) {
            std::swap(a, b);
        }
        b -= a;
    } while (b != 0);

    return a << shift;
}

int main() {
    std::ifstream fin("euclid2.in");
    std::ofstream fout("euclid2.out");
    
    int T, a, b;
    fin >> T;

    for( ; T; -- T) {
        fin >> a >> b;
        fout << gcd(a, b) << "\n";
    }

    return 0;
}