#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int MAX_NUM = 1030;

int length[MAX_NUM][MAX_NUM] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    fin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        fin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        fin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i] == b[j]) {
                length[i + 1][j + 1] = length[i][j] + 1;
            } else {
                length[i + 1][j + 1] = max(length[i + 1][j], length[i][j + 1]);
            }
        }
    }
    vector<int> arr;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            arr.push_back(a[i - 1]);
            --i, --j;
        } else if (length[i - 1][j] > length[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    reverse(arr.begin(), arr.end());
    fout << length[n][m] << "\n";
    for (int num : arr) {
        fout << num << " ";
    }
    return 0;
}
