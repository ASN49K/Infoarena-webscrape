//
// Created by Andrei Covaci on 03.09.2021.
//

#include <fstream>
#include <stack>
#include <vector>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

pair<vector<int>, vector<int>> read() {
    vector<int> a, b;
    int n, m, aux;
    in >> n >> m;
    for(; n; --n) {
        in >> aux;
        a.push_back(aux);
    }
    for(; m; --m) {
        in >> aux;
        b.push_back(aux);
    }

    return pair<vector<int>, vector<int>>(a, b);
}

stack<int> solve(pair<vector<int>, vector<int>> rows) {
    vector<int> a = rows.first, b = rows.second;

    vector<vector<int>> table;
    vector<int> col;

    for(int i = 0; i <= b.size(); ++i) {
        col.push_back(0);
    }
    for(int i = 0; i <= a.size(); ++i) {
        table.push_back(col);
    }

    for(int i = 1; i <= a.size(); ++i) {
        for(int j = 1; j <= b.size(); ++j) {
            table[i][j] = max(table[i][j - 1], table[i - 1][j]);
            if (a[i-1] == b[j-1])
                table[i][j]++;
        }
    }

    int i = a.size(), j = b.size();
    stack<int> res;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            res.push(a[i - 1]);
        }
        if (table[i - 1][j] > table[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    return res;
}

void print(stack<int> res) {
    out << res.size() << '\n';
    while (!res.empty()) {
        out << res.top() << ' ';
        res.pop();
    }
}

int main() {
    auto nums = read();
    auto res = solve(nums);
    print(res);


    return 0;
}