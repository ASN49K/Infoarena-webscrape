#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int T;
    long long a, b, aux;
    in >> T;
    while(in >> a >> b) {
        while(b) {
            aux = a % b;
            a = b;
            b = aux;
        }
        out << a << '\n';
    }
    return 0;
}