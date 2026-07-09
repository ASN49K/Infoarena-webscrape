#include <bits/stdc++.h>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

#define ll long long
#define ui unsigned int
#define pi 3.14159265359

int cmmdc(int a, int b) {
    if(a < b) swap(a, b);
    while(b) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {

    int t, x, y;
    f >> t;

    for(int i=1; i<=t; i++) {
        f >> x >> y;
        g << cmmdc(x, y) << '\n';
    }
}
