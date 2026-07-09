#include <iostream>
#include <fstream>
using namespace std;

int gcd(int a, int b){
    if(a%b == 0)
        return b;

    return gcd(b, a%b);
}

int main(){
    ifstream fr("euclid2.in");
    ofstream fw("euclid2.out");
    int t, a, b;
    fr >> t;
    while(t--){
        fr >> a >> b;
        fw << gcd(a > b ? a : b, a < b ? a : b) << '\n';
    }
    fr.close();
    fw.close();

    return 0;
}
