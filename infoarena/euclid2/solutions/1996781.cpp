#include <iostream>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int,int);

int main() {

    int t;
    in>>t;
    while(t--) {
        int x, y;
        in>>x>>y;
        out<<cmmdc(x, y)<<'\n';
    }

    return 0;
}

int cmmdc(int a, int b) {
    if(!b) return a;
    return cmmdc(b, a % b);
}
