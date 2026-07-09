#include <iostream>
#include <fstream>
#include <utility>

int gcd(int a, int b) {
    while (b) {
        a = a % b;
        std::swap(a, b);
    }
    return a;
}

int main(int argc, char** argv) {
    std::ifstream inFile;
    std::ofstream outFile;
    int nV, a, b;

    inFile.open("euclid2.in");
    outFile.open("euclid2.out");

    inFile >> nV;
    for (int i = 0; i < nV; i++) {
        inFile >> a >> b;
        outFile << gcd(a, b) << std::endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}
