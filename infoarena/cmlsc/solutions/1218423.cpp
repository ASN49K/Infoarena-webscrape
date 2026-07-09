#include <array>
#include <fstream>
#include <cstdlib>
#include <iterator>
#include <algorithm>

using namespace std;
const int NMAX = 1031;
using Strings = array<array<int, NMAX>, 3>;

void read(Strings& v) {
    ifstream in{"cmlsc.in"};
    
    in >> v[0][0] >> v[1][0];
    for (int i = 1; i <= v[0][0]; ++i) {
        in >> v[0][i];
    }
    for (int i = 1; i <= v[1][0]; ++i) {
        in >> v[1][i];
    }
}

void solve(Strings& v) {
    array<array<int, NMAX>, NMAX> dp;
    for (int i = 1; i <= v[0][0]; ++i) {
        for (int j = 1; j <= v[1][0]; ++j) {
            if (v[0][i] == v[1][j]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    v[2][0] = dp[v[0][0]][v[1][0]];
    for (int k = v[2][0], i = v[0][0], j = v[1][0]; i && j; ) {
        if (v[0][i] == v[1][j]) {
            v[2][k --] = v[0][i --];
            --j;
        }
        else if(dp[i - 1][j] >= dp[i][j - 1]) {
            --i;
        }
        else {
            --j;
        }
    }
}

void print(const Strings& v) {
    ofstream out{"cmlsc.out"};
    
    out << v[2][0] << '\n';
    copy(v[2].begin() + 1, v[2].begin() + v[2][0] + 1, ostream_iterator<int>{out, " "});
}

int main() {
    Strings v;
    
    read(v);
    solve(v);
    print(v);
    
    return EXIT_SUCCESS;
}
