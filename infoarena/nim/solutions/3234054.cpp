#include <fstream>
#include <set>
#include <cmath>
#include <stack>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <unordered_map>
#include <map>
#define ll long long

using namespace std;

ifstream cin("nim.in");
ofstream cout("nim.out");

void test_case() {
    int n, sum_xor = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        sum_xor ^= x;
    }
    cout << (sum_xor != 0 ? "DA" : "NU") << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        test_case();
    }

    return 0;
}
