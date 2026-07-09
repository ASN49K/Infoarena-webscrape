#include <fstream>
using namespace std;

int t, a, b, i;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main() {
    f>>t;
    int x;
    for (i=1; i<=t; ++i) {
        f>>a>>b;
        while (b) {
            x=b;
            b=a%b;
            a=x;
        }
        g<<a<<'\n';
    }
    return 0;
}
