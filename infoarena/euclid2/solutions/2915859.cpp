#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b);

int n, x, y;

int main(){

    fin >> n;

    for(int i = 0; i < n; i++){
        fin >> x >> y;
        fout << cmmdc(x, y) << '\n';
    }

    return 0;
}

int cmmdc(int a, int b){
    if(b == 0){
        return a;
    }

    return cmmdc(b, a % b);
}
