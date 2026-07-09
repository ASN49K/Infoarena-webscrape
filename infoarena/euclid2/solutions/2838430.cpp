#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t, a, b, i, r;

int main(){
    fin >> t;
    for(i = 1; i <= t; i++){
        fin >> a >> b;
        while(b){
            r = a % b;
            a = b;
            b = r;
        }
        fout << a << '\n';
    }
}