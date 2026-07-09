#include <bits/stdc++.h>
#pragma GCC optimize("03")
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int GCD(int a, int b){
    if(!b) return a;
    return GCD(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
    
    int t, a, b;
    fin >> t;
    while(t-- > 0){
        fin >> a >> b;
        fout << GCD(a, b) << "\n";
    }
}