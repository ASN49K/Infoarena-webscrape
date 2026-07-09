#include <iostream>
#include <fstream>
int T, A, B;
using namespace std;
int gcd(int a, int b){
    if(!b) return a;
    return gcd(b, a%b);
}

int main(){
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    f>> T;
    for(; T; --T){
        f>>A>>B;
        g<<gcd(A,B)<<'\n';
    }
    return 0;
}
