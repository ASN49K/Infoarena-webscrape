#include <iostream>
#include <fstream>
#include <stdint.h>

int main() {
    std::ifstream fin("euclid2.in");
    std::ofstream fout("euclid2.out");

    int32_t t;
    fin >> t;

    for(int32_t i = 0; i != t; ++i) {
        int32_t a, b;
        fin >> a >> b;

        while(b) {
            int32_t r = a % b;
            a = b;
            b = r;
        }

        fout << a << '\n';
    }

    fin.close();
    fout.close();

    return 0;
}