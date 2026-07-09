#include <iostream>
#include <numeric> // Required for std::gcd

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long teste;
    cin >> teste;

    while(teste--) {
        long long num1, num2;
        cin >> num1 >> num2;

        // std::gcd is available in <numeric>
        cout << gcd(num1, num2) << "\n";
    }

    return 0;
}
