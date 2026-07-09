#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

struct Ab {
    int a;
    int b;
};

int main() {
    int t;
    in >> t;

    while (t--) {
        int a, b;
        in >> a >> b;

        stack<Ab> s({{a, b}});
        while (true) {
            const auto [a, b] = s.top();
            s.pop();

            if (b == 0) {
                out << a << "\n";
                break;
            } else {
                s.emplace(Ab({b, a % b}));
            }
        }
    }

    return 0;
}