#include <bits/stdc++.h>
using namespace std;
std::ifstream cin("euclid2.in");
std::ofstream cout("euclid2.out");
int a, b;
int euclid(int a, int b) {
    int c;
    while(b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> a >> b;
        cout << euclid(a, b) << '\n';
    }
    return 0;
}