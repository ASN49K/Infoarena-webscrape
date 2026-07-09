
#include <iostream>
#include <fstream>

using namespace std;

int gcd(int a, int b) {
    if(b==0) return a;
    else return gcd(b, a % b);
} 

int main() {
    
    int a,b,n;
    
    ifstream in ("euclid2.in");
    ofstream out ("euclid2.out");
    
    in >> n;
    
    while (n) {
        in >> a >> b;
        out << gcd(a,b) << endl;
        n--;
    }
    
    in.close();
    out.close();
    
    return 0;
}


