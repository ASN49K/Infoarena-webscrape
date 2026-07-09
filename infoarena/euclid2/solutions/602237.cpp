/**
 * user: caen1
 * file: infoarena/euclid2.cpp
 * date: 23 apr 2011
**/
#include <iostream>
using namespace std;

#define IN "euclid2.in"
#define OUT "euclid2.out"

long euclid(long, long);

int main() {

    long a, b, t;

    (void) freopen(IN, "r", stdin); (void) freopen(OUT, "w", stdout);

    cin >> t;

    while(t--) {

        cin >> a >> b;

        cout << euclid(a, b);
    }

    return 0;
}

long euclid(long a, long b) {

    if(a % b) return euclid(b, a % b);
    else return b;
}

