#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int T,a,b;

int gcd(int x,int y) {
    if (y == 0) {
        return x;
    }
    return gcd(y,x%y);
}

int main() {
    in>>T;
    while (T--) {
        in>>a>>b;
        out<<gcd(a,b)<<'\n';
    }
    in.close();out.close();
    return 0;
}
