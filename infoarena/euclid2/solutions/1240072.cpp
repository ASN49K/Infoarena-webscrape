#include <fstream>
using namespace std;

int cmmdc (int a, int b) {
    int t;
    while (b) {
        t = b;
        b = a % b;
        a = t;
    }
    
    return a;
}

int main() {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    
    int t, a, b, c;
    
    for (fin >> t; t; --t) {
        fin >> a >> b;
        c = cmmdc(a, b);
        fout << c << '\n';
    }
          
    return 0;
}
