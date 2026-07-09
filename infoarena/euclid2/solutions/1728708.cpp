#include <iostream>
#include <fstream>

int euclid2(int a, int b) {
    int min = std::min(a, b);
    int greatest_divider = 1;
    for (int i = 2; i <= min; ++i) {
        if ( a % i == 0 && b % i == 0) {
            greatest_divider = i;
        }
    }
    return greatest_divider;
}

int main() {
    std::ifstream in("euclid2.in");
    std::ofstream out("euclid2.out");
    if (in) {
        int n;
        int a;
        int b;
        in >> n;
        for (int i = 0; i < n; ++i) {
            in >> a >> b;
            out << euclid2(a, b) << std::endl;
        }
    }
    return 0;
}
