#include <fstream>

int gcd(int a, int b) {
    if(!b) {
        return a;
    }
    return gcd(b, a % b);
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