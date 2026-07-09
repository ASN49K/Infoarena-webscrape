#include <bits/stdc++.h>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int t,a,b;
void read(){
    in >> a >> b;
}
int gcd(int x, int y){
    if(y) return gcd(y,x%y);
    return x;
}
int main(){
    in >> t;
    while(t--){
        read();
        out << gcd(a,b) << '\n';
    }
}
