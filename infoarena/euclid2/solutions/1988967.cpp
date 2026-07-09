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
    for (int i = 0; i < nV; i++) {
        inFile >> a >> b;
        outFile << gcd(a, b) << std::endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}
