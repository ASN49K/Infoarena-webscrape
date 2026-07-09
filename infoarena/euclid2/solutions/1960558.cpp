#include <iostream>
#include <fstream>
#include <cstdlib>

namespace standard = std;
using namespace standard;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int T,a,b;

int gcd(int x,int y) {
    if (y == 0) {
        return x;
    }
    return gcd(y,x%y);
}

void func();

int main() {
    in>>T;
    while (T--) {
        in>>a>>b;
        out<<gcd(a,b)<<'\n';
    }

    //*
    int lim = 1e7;
    for (int i=1;i<=lim;++i) {
        func();
    }
    //*/

    in.close();out.close();
    return EXIT_SUCCESS;
}

void func() {
    char v[1000] = {};
}
