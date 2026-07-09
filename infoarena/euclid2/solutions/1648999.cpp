#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

inline int Euclid(int a, int b){
    int r;
    while(b){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    int t, a, b;
    fin >> t;
    while(t--){
        fin >> a >> b;
        fout << Euclid(a, b) << "\n";
    }
    return 0  ;
}
