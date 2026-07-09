#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b){
    while(b!=0){
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main(){
    int T, a, b;
    fin >> T;
    for(int i=1; i<=T; i++){
        fin >> a >> b;
        fout << cmmdc(a,b) << '\n';
    }
    return 0;
}