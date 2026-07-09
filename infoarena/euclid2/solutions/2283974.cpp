#include <iostream>

int cmmdc(int x, int y) {
    int r = x % y;

    while (r != 0) {
        x = y;
        y = r;
        r = x % y;
    }

    return y;
}

using namespace std;

int main() {
    int numberOfTests, x, y;

    cin >> numberOfTests;

    for (int i = 0; i < numberOfTests; ++i) {
        cin >> x >> y;
        cout << cmmdc(x, y) << '\n';
    }

    return 0;
}