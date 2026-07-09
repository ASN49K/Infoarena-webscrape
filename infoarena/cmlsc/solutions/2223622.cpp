#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

const string IN_FILE = "cmlsc.in";
const string OUT_FILE = "cmlsc.out";

vector<int> getLongestCommonSubsequence(
        const vector<int>& a,
        const vector<int>& b) {
    const int m = int(a.size());
    const int n = int(b.size());
    auto dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dp[i + 1][j + 1] = a[i] == b[j]
                    ? 1 + dp[i][j]
                    : max(dp[i][j + 1], dp[i + 1][j]);
        }
    }
    vector<int> sequence;
    for (int i = m, j = n; i > 0 && j > 0; ) {
        if (a[i - 1] == b[j - 1]) {
            sequence.push_back(a[i - 1]);
            i--;
            j--;
        } else if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

vector<int> readVector(ifstream& in, const int size) {
    auto values = vector<int>(size);
    for (int i = 0; i < size; i++) {
        in >> values[i];
    }
    return values;
}

pair<vector<int>, vector<int>> readInput() {
    ifstream in(IN_FILE);
    int m, n;
    in >> m >> n;
    const auto a = readVector(in, m);
    const auto b = readVector(in, n);
    in.close();
    return make_pair(a, b);
}

void writeOutput(const vector<int>& sequence) {
    ofstream out(OUT_FILE);
    out << int(sequence.size()) << "\n";
    for (int i = 0; i < int(sequence.size()); i++) {
        out << sequence[i] << (i + 1 < int(sequence.size()) ? " " : "\n");
    }
    out.close();
}

int main() {
    vector<int> a, b;
    tie(a, b) = readInput();
    const auto sequence = getLongestCommonSubsequence(a, b);
    writeOutput(sequence);
    return 0;
}

