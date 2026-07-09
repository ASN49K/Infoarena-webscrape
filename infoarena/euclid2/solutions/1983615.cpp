#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int gcd(int a, int b){
    if(!a) return b;
    return gcd(b%a, a);
}

int t, a, b;

int main() {
    f >> t;
    while (t--)
    {
        f >> a >> b;
        g << gcd(a, b) << '\n';
    }
    f.close();
    g.close();
    return 0;
}
