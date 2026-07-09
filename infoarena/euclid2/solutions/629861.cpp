#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (a < b) {
        int c = a;
        a = b;
        b = c;
    }

    int d = b;
    b = a % b;
    a = d;

    if (b == 0) {
        return a;
    } else {
        return gcd(a, b);
    }
}

int main(int argc, char* argv[], char* envp[]) {
    int n;

    int a, b;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        cout << gcd(a, b);
    }

    return 0;
}