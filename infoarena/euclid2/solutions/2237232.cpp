#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b,cmmdc(int,int);
int main() {
    f >> t;
    for(; t; t--) {
        f >> a >> b;
        g << cmmdc(a,b) << "\n";
        }
    return 0;
    }
int cmmdc(int x,int y) {
    if(y == 0)
        return x;

    return cmmdc(y,x % y);

    }
