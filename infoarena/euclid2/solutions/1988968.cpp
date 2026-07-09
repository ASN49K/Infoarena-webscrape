#include <iostream>
#include <fstream>

using namespace std;

int gcd(int a, int b) {
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    ifstream inFile("euclid2.in");
    ofstream outFile("euclid2.out");
    int nV, a, b;

    inFile >> nV;
    while (nV) {
        inFile >> a >> b;
        outFile << gcd(a, b) << '\n';
        nV--;
    }

    inFile.close();
    outFile.close();

    return 0;
}
