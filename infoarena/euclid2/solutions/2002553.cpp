#include <iostream>

using namespace std;


void solve() {
    int n, a, b, c = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
      if (b > a) {
            c = a;
            a = b;
            b = c;
        }
        while(b){
            c = a % b;
            a = b;
            b = c;
        }
        cout << a << "\n";
    }

}

int main() {

    freopen ("euclid2.in", "r", stdin);
    freopen ("euclid2.out", "w", stdout);
    solve();
    return 0;
}