#include <cstdlib>
#include <fstream>
using namespace std;

ifstream in("cmmdc.in");

int cmmdc(int a, int b) {
    while (b) {
          int r = a%b;
          a = b;
          b = r;      
    }
    if (a == 1)
       return 0;
    return a;
}

int main() {
    int a,b;    
    in>>a>>b;
    ofstream out("cmmdc.out");
    out << cmmdc(a,b);
    out.close();
    return EXIT_SUCCESS;
}
