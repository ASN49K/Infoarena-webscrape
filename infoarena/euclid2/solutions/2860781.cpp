#include <fstream>

using namespace std;

int main() {
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    int n, a, b, r = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        r = a % b;
        while (r > 0) {
            a = b;
            b = r;
            r = a % b;
        }
        cout << b << '\n';
    }
    return 0;
}
