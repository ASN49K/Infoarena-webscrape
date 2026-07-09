#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t, a, b;

int gcd(int a, int b) {
    if(!b)
        return a;
    return gcd(b, a%b);
}

int main() {
    cin>>t;
    while(t--) {
        cin>>a>>b;
        cout<<gcd(a, b)<<"\n";
    }
    return 0;
}
