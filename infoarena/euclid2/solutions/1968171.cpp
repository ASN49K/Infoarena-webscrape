#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in"); ofstream g("euclid2.out");

int n,a,b;

int cmmdc(int x, int y) {
    int r;
    do {
        r = x % y;
        x = y;
        y = r;
    }
    while (r > 0);
    return x;
}
int main(){
    int i;
    f>>n;
    for(i = 1; i <= n; ++i) {
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
