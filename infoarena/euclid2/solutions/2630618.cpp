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
        if(j < min(a,b)) {
            if (a && b % j == 0) {
                d =j;
            }
        }
    }
    cout << d;
    return 0;
}
