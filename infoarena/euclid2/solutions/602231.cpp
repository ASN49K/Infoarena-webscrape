/**
 * user: caen1
 * file: infoarena/euclid2.cpp
 * date: 23 apr 2011
**/
#include <cstdio>
using namespace std;

#define IN "euclid2.in"
#define OUT "euclid2.out"

unsigned long cmmdc(unsigned long, unsigned long);

int main() {

    unsigned long a, b, t;

    (void) freopen(IN, "r", stdin); (void) freopen(OUT, "w", stdout);

    (void) scanf("%ld", &t);

    while(t--) {

        (void) scanf("%ld %ld", &a, &b);

        printf("%ld\n", cmmdc(a, b));
    }

    return 0;
}

unsigned long cmmdc(unsigned long a, unsigned long b) {

    if(a % b) return cmmdc(b, a % b);
    else return b;
}

