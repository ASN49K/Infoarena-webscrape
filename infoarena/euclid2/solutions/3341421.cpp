#include <fstream>

int gcd(int a, int b) {
    if(a == b) {
        return a;
    }
    if(!((a | b) & 1)) {
        return gcd(a >> 1, b >> 1) << 1;
    }
    if(!(a & 1)) {
        return gcd(a >> 1, b);
    }
    if(!(b & 1)) {
        return gcd(a, b >> 1);
    }
    if(a >= b) {
        return gcd(a - b, b);
    }
    return gcd(a, b - a);
}

int main() {
    std::ifstream fin("euclid2.in");
    std::ofstream fout("euclid2.out");
    
    int T, a, b;
    fin >> T;

    for( ; T; -- T) {
        fin >> a >> b;
        fout << gcd(a, b) << std::endl;
    }

    return 0;
}