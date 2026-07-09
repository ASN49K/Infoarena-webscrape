#include <iostream>
using namespace std;

int cmmdc(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        int firstNumber, secondNumber;
        cin >> firstNumber >> secondNumber;
        cout << cmmdc(firstNumber, secondNumber) << '\n';
    }
    return 0;
}
