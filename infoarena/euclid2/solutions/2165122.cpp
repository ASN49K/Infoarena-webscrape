#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b) {
    int r = a % b;

    while(r){
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

int main() {
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    int N;
    cin >> N;
    while(N--) {
        int a, b;

        cin >> a >> b;

        cout << gcd(a, b) << '\n';
    }

    return 0;
}
