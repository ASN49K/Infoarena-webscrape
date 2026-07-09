#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

template<class T>
std::vector<T> LonComSubStr(const std::vector<T> &a, const std::vector<T> &b) {
    std::vector<std::vector<int>> x;
    x.resize(b.size(), std::vector<int>(a.size()));
    for (int i = 1; i < b.size(); i++) {
        for (int j = 1; j < a.size(); j++) {

            if (b[i] == a[j]) {
                x[i][j] = x[i - 1][j - 1] + 1;
            } else {
                x[i][j] = std::max(x[i - 1][j], x[i][j - 1]);
            }
        }
    }
    std::vector<T> sol;
    int i = b.size() - 1, j = a.size() - 1;
    while (x[i][j]) {
        if (b[i] != a[j]) {
            if (x[i][j] == x[i - 1][j]) i--;
            else j--;
        } else {
            sol.push_back(b[i]);
            i--;
            j--;
        }
    }
    std::reverse(sol.begin(), sol.end());
    return sol;
}

int main() {
    std::ifstream fin("cmlsc.in");
    int na, nb;
    fin >> na >> nb;
    std::vector<short> a(1), b(1);
    int f;
    for (int i = 0; i < na; i++) {
        fin >> f;
        a.push_back(f);
    }
    for (int i = 0; i < nb; i++) {
        fin >> f;
        b.push_back(f);
    }
    std::vector<short> res = LonComSubStr(a, b);

    std::ofstream fout("cmlsc.out");

    fout << res.size() << "\n";
    for (int e:res)
        fout << e << " ";

    return 0;
}
