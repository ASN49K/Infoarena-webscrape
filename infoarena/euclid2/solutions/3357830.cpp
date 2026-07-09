#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        cout << a << '\n';
    }
    return 0;
}