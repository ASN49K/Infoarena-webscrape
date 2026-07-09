#include <bits/stdc++.h>
using namespace std;

int binary_gcd(int x, int y){
    int shift = 0;
    while(x && y){
        if(~x & ~y & 1) x >>= 1, y >>= 1, ++shift;
        else if(~x & 1) x >>= 1;
        else if(~y & 1) y >>= 1;
        else if(x > y) x -= y, x >>= 1;
        else y -= x, y >>= 1; }
    return (x | y) << shift; }

int main(){
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int t;
    f >> t;
    for(int a, b; t; --t){
        f >> a >> b;
        g << __gcd(a, b) << '\n'; }
    return 0; }
