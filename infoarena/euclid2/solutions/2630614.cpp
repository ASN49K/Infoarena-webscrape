#include <iostream>

using namespace std;

int main()
{
    int T, a, b, d, g;
    cin >> T;
    for (int i = 0; i<T; ++i){
        cin >> a >> b;
    }
    for (int j = 1; j<max(a,b); ++j) {
        if (a && b % j == 0 && j < min(a,b)) {
            d = j;

        }
    }
    cout << d;
    return 0;
}
