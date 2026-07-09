#include <cstdlib>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");

int cmmdc(int a, int b) {
    while (b) {
          int r = a%b;
          a = b;
          b = r;      
    }
    return a;
}

int main() {
    int a,b;    
    in>>a>>b;
    ofstream out("eucllid2.out");
    out << cmmdc(a,b);
    out.close();
    return EXIT_SUCCESS;
}
