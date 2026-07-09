#include <iostream>
#include <fstream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, b % a);
}

int main(int argc, char* argv[], char* envp[]) {
    int n;

    int a, b;

    ifstream in;
    in.open("euclid2.in");

    ofstream out;
    out.open("euclid2.out");

    in >> n;

    for (int i = 0; i < n; ++i) {
        in >> a >> b;
        out << gcd(a, b) << endl;
    }

    in.close();
    out.close();

    return 0;
}