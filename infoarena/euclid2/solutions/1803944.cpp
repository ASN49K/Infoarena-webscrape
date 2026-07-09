#include <iostream>
#include<stdio.h>
using namespace std;

inline int max(int x, int y) { return (x > y ? x : y); }

int main() {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int A, B, ret = 1;
    cin >> A >> B;

    for (int i = 1; i*i <= A; ++i)
        if (A % i == 0) {
            if (B % i == 0)
                ret = max(ret, i);
            if (B % (A/i) == 0)
                ret = max(ret, A/i);
        }
    cout << ret;
}
