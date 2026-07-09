#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a, int b) {
    if (b)
        return cmmdc(b, a % b);
    return a;
}

int main() {
    int t, a, b;

    ifstream infile("euclid2.in");
    ofstream outfile("euclid2.out");

    infile >> t;

    while(infile >> a >> b)
        outfile << cmmdc(a, b) << "\n";
}
