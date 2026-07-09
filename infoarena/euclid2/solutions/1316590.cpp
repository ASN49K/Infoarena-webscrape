#include<fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b) {
    if(a) return gcd(b%a, a);
    else return b;
}

int main() {
    int T, a, b;
    fin>>T;
    while(T--) {
        fin>>a>>b;
        if(a>b) swap(a, b);
        fout<<gcd(a, b);
    }
    return 0;
}
