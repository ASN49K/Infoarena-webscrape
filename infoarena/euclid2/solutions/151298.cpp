#include <cstdlib>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");

long cmmdc(long a, long b) {
    while (b) {
          long r = a%b;
          a = b;
          b = r;      
    }
    return a;
}

int main() {
    long a,b;    
    in>>a>>b;
    ofstream out("euclid2.out");
    out << cmmdc(a,b);
    out.close();
    return 0;
}
