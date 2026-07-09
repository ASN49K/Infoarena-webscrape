#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int gcd(int a, int b){
    int c;
    while (b){
        c = a % b;
        if (!c) return b;
        a = b % c;
        if (!a) return c;
        b = c % a;
    }
    return a;
}

int binaryGCD(int a, int b){
    int x = __builtin_ctz(a), y = __builtin_ctz(b);
    a >>= x; b >>= y;
    if (y < x) x = y;

    while (a != b){
        if (a > b){
            a -= b;
            a >>= __builtin_ctz(a);
        } else {
            b -= a;
            b >>= __builtin_ctz(b);
        }
    }
    return a << x;
}

int main(){
    int times, x, y;

    in >> times;
    while (times--){
        in >> x >> y;
        out << gcd(x, y) << "\n";
    }
    return 0;
}
