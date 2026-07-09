#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a, int b) {
    int r;
    while(b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main() {
    int t, a, b;
    in>>t;
    while(t--) {
        in>>a>>b;
        out<<euclid(a,b)<<"\n";
    }

    return 0;
}
