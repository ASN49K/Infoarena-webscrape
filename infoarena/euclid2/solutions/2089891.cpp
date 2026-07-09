#include <iostream>
using namespace std;
 
inline int max(int a, int b) { return (a > b ? a : b); }
 
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
