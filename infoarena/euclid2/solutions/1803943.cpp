#include <iostream>
#include<fstream>
using namespace std;

inline int max(int x, int y) { return (x > y ? x : y); }

int main() {
    fstream f("euclid2.in");
    fstream g("euclid2.out");

    int A, B, ret = 1;
    f>> A >> B;

    for (int i = 1; i*i <= A; ++i)
        if (A % i == 0) {
            if (B % i == 0)
                ret = max(ret, i);
            if (B % (A/i) == 0)
                ret = max(ret, A/i);
        }
    g << ret;
}
