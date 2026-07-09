#include <fstream>

using namespace std;

const char *INPUT_FILE_PATH = "euclid2.in";
const char *OUTPUT_FILE_PATH = "euclid2.out";

namespace math {
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
}

int main() {
    ifstream cin(INPUT_FILE_PATH);
    ofstream cout(OUTPUT_FILE_PATH);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << math::gcd(a, b) << "\n";
    }
    return 0;
}