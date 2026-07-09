#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>
#include <vector>
#include <assert.h>

using LL = long long;
using ULL = int long long;

const std::string _problemName = "cmlsc";

namespace std {
std::ifstream fin(_problemName + ".in"); 
std::ofstream fout(_problemName + ".out"); 
}

#define cin fin
#define cout fout

std::vector<int> buildLCS(const std::vector< std::vector<int> >& lcs, const std::vector<int>& a, const std::vector<int>& b) {
    int i = a.size();
    int j = b.size();
    std::vector<int> result(lcs[i][j]);

    while (lcs[i][j] > 0) {
        if (lcs[i - 1][j - 1] + 1 == lcs[i][j]) {
            --i;
            --j;
            assert(a[i] == b[j]);
            result[ lcs[i][j] ] = a[i];
        }
        else if (lcs[i - 1][j] == lcs[i][j]) { 
            --i;
        }
        else { // if (lcs[i][j - 1] == lcs[i][j])
            --j;
        }
    }

    return result;
}
int main() {

    int n, m;

    std::vector<int> a;
    std::vector<int> b;

    std::cin >> n >> m;

    a.reserve(n);
    b.reserve(m);

    while (n--) {
        int x;
        std::cin >> x;
        a.push_back(x);
    }

    while (m--) {
        int x;
        std::cin >> x;
        b.push_back(x);
    }

    std::vector<std::vector<int>> lcs;

    lcs.emplace_back(b.size() + 1, 0);

    for (int aIdx = 1; aIdx <= a.size(); ++aIdx) {
        lcs.emplace_back(b.size() + 1, 0);

        for (int bIdx = 1; bIdx <= b.size(); ++bIdx) {
            if (a[aIdx - 1] == b[bIdx - 1]) {
                lcs[aIdx][bIdx] = lcs[aIdx - 1][bIdx - 1] + 1;
            }
            else {
                lcs[aIdx][bIdx] = std::max(lcs[aIdx - 1][bIdx], lcs[aIdx][bIdx - 1]);
            }
        }
    }
    
    std::vector<int> sequence = buildLCS(lcs, a, b);
    
    std::cout << sequence.size() << '\n';
    for (int i : sequence) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}