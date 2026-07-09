#include<fstream>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int a, b;

int gcd(int a, int b) {
    if(b) return a;
    return gcd(b, a%b);
}

int main () {
    cout<<gcd(a,b);
    return 0;
}
