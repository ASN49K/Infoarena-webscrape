#include <fstream> 

using namespace std;

int gcd(int a,int b) {
    
    if( !a || !b) return a | b;
    
    int g = 0;
    do {
        if( !(a&1) && !(b&1) ) g++;
        if ( !(a&1) ) a >>= 1;
        if( ! (b&1) ) b >>= 1;
        if( (a&1) && (b&1) )  a < b ? (b -= a) >> 1  : (a -= b) >> 1;
    }
    while(a && b);
    
    return (a ? a : b) << g;
}

int main() {
    
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    
    int T;
    
    fin >> T;
    while(T--) {
               
               int a,b;
               fin >> a >> b;
               fout << gcd(a,b) << '\n';
    }
    
    return 0;
}
