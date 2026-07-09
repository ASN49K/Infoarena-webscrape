#include <iostream>

using namespace std;

int T, A, B;

int cmmdc(int a, int b)
{
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    
    for (scanf("%d", &T); T; --T) {
        scanf("%d %d", &A, &B);
        printf("%d\n", cmmdc(A, B));
    }
    
    for (scanf("%d", &T); T; --T) {
        scanf("%d %d", &A, &B);
        printf("%d\n", cmmdc(A, B));
    };
}