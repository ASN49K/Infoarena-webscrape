#include <iostream>

using namespace std;

    int gcd(int a, int b) {

        if (!b)
        return a;

        return gcd(b, a % b);

    }

int main()
{
    int a, b, n;
    cin >> n;

    while (n--) {
        cin >> a >> b;
        cout << gcd(a, b);
    }
    return 0;
}
