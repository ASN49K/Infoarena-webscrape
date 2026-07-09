#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int n,a,b;

int main() {
    in>>n;
    while(n--){
        in>>a>>b;

        out<<__gcd(a,b)<<endl;
    }
    return 0;
}
