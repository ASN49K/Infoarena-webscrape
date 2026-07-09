#include <iostream>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    int a, b;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        cout << a << endl;
    }
    
    return 0;
}