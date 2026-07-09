#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int euclid (int a, int b) {
    if (b == 0) return a;
    return euclid(b, a % b);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        cout << euclid(a,b) << '\n';
    }
    return 0;
}