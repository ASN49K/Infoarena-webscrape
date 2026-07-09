#include <bits/stdc++.h>
#pragma GCC optimize("03")
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int GCD(int a, int b){
    if(a == 0) return b;
    return GCD(b%a, a);
}

int main(){
    ios::sync_with_stdio(false);
    
    int t, a, b;
    fin >> t;
    for(int i = 0; i < t; i++){
        fin >> a >> b;
        fout << GCD(a, b) << endl;
    }
}