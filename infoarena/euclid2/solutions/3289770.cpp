#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t, a, b, d;

int main(){
    fin >> t;
    for(int i = 1; i <= t; ++i){
        fin >> a >> b;
        d = __gcd(a, b);
        fout << d << '\n';
    }
}