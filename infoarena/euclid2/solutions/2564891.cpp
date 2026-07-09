#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#define ll long long

using namespace std;

int euclid(int a, int b) {
    while(b) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {

    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    int ntests;
    in >> ntests;
    while(ntests --) {
        int a, b;
        in >> a >> b;
        out << euclid(a, b) << "\n";
    }

    return 0;
}
