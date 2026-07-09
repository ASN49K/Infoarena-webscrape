#include <fstream>
using namespace std;

ifstream fi;
ofstream fo;
int n;
long long a, b, t;

inline long long gcd(long long a, long long b) {
    while (b != 0){
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    fi.open("euclid.in");
    fo.open("euclid.out");
    fi >> n;
    for (int i = 0; i< n; i++){
        fi >> a;
        fi >> b;
        fo << gcd(a, b) << "\n";
    }
    fi.close();
    fo.close();
    return 0;
}
