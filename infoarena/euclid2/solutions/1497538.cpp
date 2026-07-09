#include <iostream>

using namespace std;

void outputCMMDC(int a, int b) {
    int max =  a > b ? a : b;
    for (int x = max; x >= 2; x--) {
        if (a % x == 0 && b % x == 0) {
            cout << x << endl;
            return;
        }
    }
    cout << "1" << endl;
}

int main() {
    int num;
    cin >> num;

    int i = 0;
    int a = 0;
    int b = 0;
    while (i++ < num) {
        cin >> a;
        cin >> b;
        outputCMMDC(a, b);
    }

    return 0;
}


