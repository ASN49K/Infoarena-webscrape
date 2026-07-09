#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;
ifstream in("euclid1.in");
ofstream out("euclid1.out");

int gcd(int a,int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b,a%b);
}

int main() {
    int T;
    in>>T;

    while (T--) {
        int a,b;
        in>>a>>b;
        out<<gcd(a,b)<<'\n';
    }

    in.close();out.close();
    return 0;
}

