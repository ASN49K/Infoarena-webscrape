#include <bits/stdc++.h>

using namespace std;

ifstream fi("euclid2.in");
ofstream fo("euclid2.out");

int cmmdc(int a, int b) {
    int c;
    while(b) {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int a, b, x;
int main()
{
    fi >> x;
    for(int i = 0; i < x; i ++) {
        fi >> a >> b;
        fo << cmmdc(a, b) << '\n';
    }
    return 0;
}
