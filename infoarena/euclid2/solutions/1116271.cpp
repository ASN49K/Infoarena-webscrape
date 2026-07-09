#include <iostream>
#include <fstream>

using namespace std;

#define dimen 1000001

int n,nr1,nr2;

int gcd(int a,int b){
    if (!b){
        return a;
    }
    return gcd(b,a%b);
}

int main(){
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    f >> n;

    for (int i=0;i<n;++i){
        f >> nr1 >> nr2;
        g << gcd(nr1, nr2) << "\n";
    }

    f.close();
    g.close();
    return 0;
}
