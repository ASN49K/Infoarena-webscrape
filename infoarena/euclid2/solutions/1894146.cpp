//
// Created by Teodor Poncu on 2/26/17.
//

#include <iostream>

int cmmdc(int a, int b) {
    if (!b) return a;
    return cmmdc(b, b % a);
}


int main() {

    int a, b, count;

    std::freopen("euclid2.in", "r", stdin);
    std::freopen("euclid2.out", "w", stdout);

    scanf("%d", &count);

    for(; count; --count) {
        scanf("%d %d", &a, &b);
        printf("%d\n", cmmdc(a, b));
    }

    return 0;

}
