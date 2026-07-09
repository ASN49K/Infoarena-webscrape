#include <iostream>
#include <fstream>

using namespace std;

// Function to calculate GCD using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    ifstream infile("euclid2.in");
    ofstream outfile("euclid2.out");

    if (!infile || !outfile) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    int T;
    infile >> T;

    for (int i = 0; i < T; ++i) {
        int a, b;
        infile >> a >> b;
        outfile << gcd(a, b) << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
