#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");

    int T, r;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        unsigned long a, b;
        cin >> a >> b;

        while (b) {
            r = a % b;
            a = b;
            b = r;
        }
        cout << a << endl;
    }
    return 0;
}