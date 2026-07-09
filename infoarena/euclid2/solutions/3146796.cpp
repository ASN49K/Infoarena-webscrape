//https://www.infoarena.ro/problema/euclid2
#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");


int gcd(int a, int b){
    int r;
    while(b){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main() {
    int T;
    in>>T;
    while(T--){
        int a,b;
        in>>a>>b;
        out<<gcd(a,b)<<'\n';
    }
    return 0;
}