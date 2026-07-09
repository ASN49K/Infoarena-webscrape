#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");
int cmmdc(int c, int d) {
    int r = c%d;
    if(r != 0) {
        c = d;
        return cmmdc(c, r);
    }
    return d;
}

int t, a, b;
int main()
{
    in >> t;
    for(int i = 0; i < t; i++) {
        in >> a >> b;
        out << cmmdc(a, b) << "\n";
    }
    return 0;
}
