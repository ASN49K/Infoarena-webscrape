#include <iostream>

using namespace std;

int cmmdc(int a, int b) {
    if (a == b)
        return a;
    if (a > b)
        cmmdc(a - b, b);
    else
        cmmdc(a, b - a);
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        cout << cmmdc(a, b) << "\n";
    }
}
