#define __EUCLID2__

#ifdef __EUCLID2__

#include <iostream>
#include <fstream>

int euclid(int a, int b) {
    while (a != b) {
        if (a < b) {
            std::swap(a, b);
        }

        a = a % b;

        if (a == 0) {
            return b;
        }
    }

    return a;
}

int main() {
    std::ifstream fin("euclid2.in");
    std::ofstream fout("euclid2.out");

    int n;
    fin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        fin >> a >> b;
        fout << euclid(a, b) << "\n";
    }
    return 0;
}

#endif