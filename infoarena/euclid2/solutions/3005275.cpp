#include <bits/stdc++.h>
using namespace std;
ifstream fr("euclid2.in");
ofstream fw("euclid2.out");

int gcd(int a, int b){
    if(a % b == 0)
        return b;

    return gcd(b, a%b);
}

int main(){
    int t;
    fr >> t;
    while(t--){
        int a, b;
        fr >> a >> b;
        fw << gcd(a, b) << '\n';
    }
    fr.close();
    fw.close();

    return 0;
}
