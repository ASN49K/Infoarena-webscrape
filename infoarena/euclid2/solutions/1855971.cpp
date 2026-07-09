#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int t;
    f >> t;
    for(int a, b; t; --t){
        f >> a >> b;
        g << __gcd(a, b) << '\n'; }
    return 0; }
