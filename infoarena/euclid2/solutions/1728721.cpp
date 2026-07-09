#include <iostream>
#include <fstream>

int euclid2(int a, int b) {
    int temp;
    while(b) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
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
            out << euclid2(a, b) << "\n";
        }
    }
    return 0;
}
