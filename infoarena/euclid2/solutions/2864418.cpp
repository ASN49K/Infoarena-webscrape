#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

ifstream fin("input.in");
ofstream fout("output.out");

int euclid(int a, int b) {
    int rest = a % b;
    while (rest) {
        a = b;
        b = rest;
        rest = a % b;
    }
    return b;
}

int main() {
    int t;
    int a, b;
    fin >> t;
    for (int i = 0; i < t; i++) {
        fin >> a >> b;
        fout << euclid(a, b) << "\n";
    }

    return 0;
}