#include <iostream>
#include <fstream>

int cmmdc(int x, int y) {
    int r = x % y;

    while (r != 0) {
        x = y;
        y = r;
        r = x % y;
    }

    return y;
}

using namespace std;

int main() {
    ifstream readInput("euclid2.in");
    ofstream writeOutput("euclid2.out");

    int numberOfTests, x, y;

    readInput >> numberOfTests;

    for (int i = 0; i < numberOfTests; ++i) {
        readInput >> x >> y;
        writeOutput << cmmdc(x, y) << '\n';
    }

    return 0;
}