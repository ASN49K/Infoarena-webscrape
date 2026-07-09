#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

vector<int> ReadVector(ifstream& fin, int size) {
    vector<int> vec(size);
    for (auto &num : vec) {
        fin >> num;
    }
    return vec;
}

vector<int> Solve(const vector<int>& a, const vector<int>& b) {
    vector<vector<int>> dp(a.size(), vector<int>(b.size(), 0));
    for (size_t i = 0; i < a.size(); i += 1) {
        for (size_t j = 0; j < b.size(); j += 1) {
            if (a[i] == b[j]) {
                dp[i][j] = 1 + (i > 0 && j > 0 ? dp[i - 1][j - 1] : 0);
            } else {
                dp[i][j] = max(
                    (i > 0) ? dp[i - 1][j] : (1 << 30),
                    (j > 0) ? dp[i][j - 1] : (1 << 30)
                );
            }
        }
    }

    vector<int> res;
    res.reserve(dp.back().back());

    int row = a.size() - 1;
    int col = b.size() - 1;
    while (row >= 0 && col >= 0) {
        if (a[row] == b[col]) {
            res.push_back(a[row]);
            row -= 1;
            col -= 1;
            continue;
        }

        if (col == 0 || (row > 0 && dp[row - 1][col] > dp[row][col - 1])) {
            row -= 1;
        } else {
            col -= 1;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int n, m;
    fin >> n >> m;

    auto a = ReadVector(fin, n);
    auto b = ReadVector(fin, m);

    auto res = Solve(a, b);
    fout << res.size() << "\n";
    for (const auto& num : res) {
        fout << num << " ";
    }
    fout << "\n";

    return 0;
}
