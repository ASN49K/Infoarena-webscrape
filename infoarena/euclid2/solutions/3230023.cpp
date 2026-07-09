#include <fstream>
using namespace std;

ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");

void solve() {
    int n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        while (b) {
            int r = a % b;
            a = b;
            b = r;
        }
        cout << a << '\n';
    }
}

int main () {
    solve();
}