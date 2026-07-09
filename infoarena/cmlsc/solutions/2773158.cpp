//
// Created by Andrei Covaci on 03.09.2021.
//

#include <fstream>
#include <stack>
#include <vector>
#include <unordered_map>

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

    int i, j;

    for(i = 0; i <= b.size(); ++i) {
        col.push_back(0);
    }
    for(i = 0; i <= a.size(); ++i) {
        table.push_back(col);
    }

    for(i = 1; i <= a.size(); ++i) {
        for(j = 1; j <= b.size(); ++j) {
            if (a[i-1] == b[j-1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
            } else {
                table[i][j] = max(table[i][j - 1], table[i - 1][j]);
            }
        }
    }

    stack<int> res;

    i = a.size();
    j = b.size();

    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            res.push(a[i - 1]);
            --i;
            --j;
        } else if (table[i - 1][j] > table[i][j - 1]) {
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