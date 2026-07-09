
#include <iostream>
#include <fstream>

using namespace std;

int gcd(int, int);

int main(int argc, const char * argv[]) {
    
    int a,b,n;
    
    ifstream in ("euclid2.in");
    ofstream out ("euclid2.out");
    
    in >> n;
    
    while (n) {
        in >> a >> b;
        out << gcd(a,b);
        n--;
    }
    
    in.close();
    out.close();
    
    return 0;
}

int gcd(int a, int b) {
    if(b==0) return a;
    else return gcd(b, a % b);
}
