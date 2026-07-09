#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <random>
#include <climits>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {
    int t;
    fin >> t;
    while (t--) {
        int a, b;
        fin >> a >> b;
        fout << gcd(a, b) << "\n";
    }

    return 0;
}