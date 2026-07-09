#include<fstream>


int gcd(int a, int b) {

    if(!b)
        return a;

    return gcd(b, a % b);
}


int main() {
    std::ifstream in("euclid2.in");
    std::ofstream out("euclid2.out");

    int a, b, t;

    in>>t;
    while(t--) {
        in>>a>>b;
        out<<gcd(a,b)<<"\n";
    }

    return 0;
}
