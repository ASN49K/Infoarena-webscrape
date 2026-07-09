#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

vector<int> ReadVector(istream& in, int size) {
    vector<int> vec(size);
    for (auto& num : vec) {
        in >> num;
    }
    return vec;
}

vector<int> ExtractCommon(const vector<int>&a, const vector<int>& b,
                          const vector<vector<int>>& dp) {
    vector<int> common(dp.back().back());
    int index = common.size() - 1;

    int r = a.size() - 1;
    int c = b.size() - 1;

    while (r >= 0 && c >= 0) {
        if (a[r] == b[c]) {
            common[index] = a[r];
            index -= 1;
            r -= 1;
            c -= 1;
        } else if (r > 0 && (c == 0 || dp[r - 1][c] >= dp[r][c - 1])) {
            r -= 1;
        } else {
            c -= 1;
        }
    }
    return common;
}

vector<int> LongestCommon(const vector<int>& a, const vector<int>& b) {
    vector<vector<int>> dp(a.size(), vector<int>(b.size(), 0));
    for (size_t i = 0; i < a.size(); i += 1) {
        for (size_t j = 0; j < b.size(); j += 1) {
            if (a[i] == b[j]) {
                dp[i][j] = 1 + (i > 0 && j > 0 ? dp[i - 1][j - 1] : 0);
            } else {
                dp[i][j] = max({
                    (i > 0 ? dp[i - 1][j] : 0),
                    (j > 0 ? dp[i][j - 1] : 0),
                    (i > 0 && j > 0 ? dp[i - 1][j - 1] : 0),
                });
            }
        }
    }
    return ExtractCommon(a, b, dp);
}

int main() {
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int n, m;
    fin >> n >> m;

    auto a = ReadVector(fin, n);
    auto b = ReadVector(fin, m);

    auto common = LongestCommon(a, b);
    fout << common.size() << "\n";
    for (const auto& num : common) {
        fout << num << " ";
    }
    fout << "\n";

    return 0;
}
