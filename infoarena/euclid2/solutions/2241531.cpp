#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>
#include <vector>

using LL = long long;
using ULL = int long long;

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
}

const std::string _problemName = "euclid2";

namespace std {
std::ifstream fin(_problemName + ".in"); 
std::ofstream fout(_problemName + ".out"); 
}

#define cin fin
#define cout fout


int main() {

    int t;
    std::cin >> t;

    while (t--) {
        int a, b;
        std::cin >> a >> b;
        std::cout << __gcd(a, b) << '\n';
    }

    return 0;
}