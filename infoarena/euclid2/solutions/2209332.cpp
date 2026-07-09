#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t,a,b;


int euclid(int a, int b) {
    while(b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}



int main() {

    f >> t;
    for(int i = 0; i < t; i++) {
        f >> a >> b;
        g << euclid(a,b) << "\n";
    }
}
