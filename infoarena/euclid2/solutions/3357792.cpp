#include <iostream>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n, a, b;
    in >> n;

    for (int i = 0; i < n; i++) {
        in >> a >> b;
        out << cmmdc(a, b) << '\n';
    }

    return 0;
}