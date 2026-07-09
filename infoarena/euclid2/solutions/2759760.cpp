#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int gcd(int a, int b) {
    int t;

    while (b) {
        t = a;
        a = b;
        b = t % b;
    }

    return a;
}

int main() {
    string T;
    string as, bs;

    ifstream euclidIn("euclid2.in");
    ofstream euclidOut("euclid2.out");

    euclidIn >> T;

    for (int i = 0; i < stoi(T); i++) {
        euclidIn >> as >> bs;
        int a = stoi(as);
        int b = stoi(bs);
        
        euclidOut << gcd(a, b) << endl;
    }
    
    return 0;
}