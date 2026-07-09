#include <fstream>

std::ifstream fin("euclid2.in");
std::ofstream fout("euclid2.out");

uint64_t euclid(uint64_t a, uint64_t b) {
    while(b!=0) {
        const int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int n;
    fin >> n;
    for (int i = 0; i < n; i++) {
        uint64_t a, b;
        fin >> a >> b;
        fout << euclid(a, b) << '\n';
    }
    return 0;
}