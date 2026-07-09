#include <iostream>

using namespace std;

int TESTS, x, y;

int cmmdc(int X, int Y) {
    while(Y) {
        int Z = X % Y;
        X = Y, Y = Z;
    }
    return X;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &TESTS);
    while(TESTS--) scanf("%d%d", &x, &y), printf("%d\n", cmmdc(x, y));
    return 0;
}
