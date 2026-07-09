#include <iostream>

using namespace std;


void solve() {
    int n, a, b, c;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);

        while(b){
            c = a % b;
            a = b;
            b = c;
        }
        printf("%d\n", a);
    }

}

int main() {

    freopen ("euclid2.in", "r", stdin);
    freopen ("euclid2.out", "w", stdout);
    solve();
    return 0;
}