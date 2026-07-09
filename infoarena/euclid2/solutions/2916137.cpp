#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n;
int main(){

    fin >> n;
    while(n--){
        int x ,y;
        fin >> x >> y;
        fout << __gcd(x, y) << '\n';
    }
}