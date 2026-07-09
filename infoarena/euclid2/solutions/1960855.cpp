#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int T,a,b;

int euclid(int x,int y) {
    if (y == 0) {
        return x;
    }
    return euclid(y,x%y);
}

void func() {
    char v[1000] = {};
}
int main() {
    f>>T;
    while (T--) {
        f>>a>>b;
        g<<euclid(a,b)<<'\n';
    }

    int lim = 10000000;
    for (int i=1;i<=lim;++i) {
        func();
    }

    return EXIT_SUCCESS;
}


