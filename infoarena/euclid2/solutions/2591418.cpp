#include <iostream>
#include <fstream>

std :: ifstream in("euclid2.in");
std :: ofstream out("euclid2.out");

int gcd(int a, int b) {
    if (!b)
        return a;
    return gcd(b, a % b);
}

int main() {
    int T, A, B;
    in >> T;
    for (; T; --T) {
        in >> A >> B;
        out<<gcd(A, B)<<"\n";
    }
    return 0;
}
