#include <fstream>
#include <cmath>

std::ifstream fin("euclid2.in");
std::ofstream fout("euclid2.out");

int n, a, b, res;

int main() {
    fin >> n;
    while(n--) {
        fin >> a >> b;
        fout << std::__gcd(a, b) << '\n';
    }
    return 0;
}
