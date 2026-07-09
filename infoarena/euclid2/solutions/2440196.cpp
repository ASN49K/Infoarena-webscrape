#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");


int cmmdc(int a, int b) {
    int r;
    while(b !=0 ) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

/*int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}*/

int main() {
    int a, b, n;
    in >> n;
    while (n) {
        in >> a >> b;
        out << cmmdc(a, b) << "\n";
        n--;
    }
    return 0;
}
