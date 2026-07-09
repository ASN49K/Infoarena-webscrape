#include <fstream>

int gcd(int a, int b) {
    int rest;
    while (b) {
        rest = a % b;
        a = b;
        b = rest;
    }
    return a;
}

int main() {
    int n = 0, a, b;

    std::fstream input_file;
    std::fstream output_file;

    input_file.open("euclid2.in", std::ios::in);
    output_file.open("euclid2.out", std::ios::out | std::ios::trunc);

    input_file >> n;
    while (input_file >> a >> b && output_file << gcd(a, b) << '\n');
    
    input_file.close();
    output_file.close();
    return 0;
}
