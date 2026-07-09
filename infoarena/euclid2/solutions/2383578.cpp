#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a%b));
}

int main(){
    int t;
    in>>t;
    for(int i = 1, a, b; i <= t; ++i) in>>a>>b, out<<gcd(a, b)<<"\n";
    return 0;
}
