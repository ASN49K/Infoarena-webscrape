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

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main() {
    int n, m;
    fin >> n >> m;

    int a[n + 1];
    for (int i = 0; i < n; ++i) {
        fin >> a[i];
    }

    int b[m + 1];
    for (int i = 0; i < m; ++i) {
        fin >> b[i];
    }

    int longestCommonSubstring[n + 1][m + 1];

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            longestCommonSubstring[i][j] = 0;
        }
    }

    vector<int> commonSubarray;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                if (longestCommonSubstring[i][j] < longestCommonSubstring[i - 1][j - 1] + 1) {
                    longestCommonSubstring[i][j] = longestCommonSubstring[i - 1][j - 1] + 1;
                    commonSubarray.push_back(a[i - 1]);
                }
            } else {
                longestCommonSubstring[i][j] = max(longestCommonSubstring[i - 1][j], longestCommonSubstring[i][j - 1]);
            }
        }
    }

    fout << longestCommonSubstring[n][m];
    fout << "\n";

    for (auto number : commonSubarray) {
        fout << number << " ";
    }

    return 0;
}