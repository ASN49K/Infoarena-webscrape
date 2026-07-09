/*

cat timp b > 0 repeta
| r <- a % b
| a <- b
| b <- r
\[]
cautam a
*/

#include<fstream>
#include<iostream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main() {
    int t, i, a, b, r;

    in>>t;

    for (i = 1; i <= t; i++) {
        in>>a>>b;

        while (b > 0) {
            r = a % b;
            a = b;
            b = r;
        }

        out<<a<<"\n";

    }

    return 0;
}
