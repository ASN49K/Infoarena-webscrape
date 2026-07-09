#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

ifstream fin  ("euclid2.in");
ofstream fout ("euclid2.out");

int cmmdc(int a, int b){
    int r;
    while(b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main (){
    ios_base::sync_with_stdio(false);
    fin.tie(nullptr), fout.tie(nullptr);

    int qcnt, a, b;
    fin>>qcnt;
    while(qcnt--){
        fin>>a>>b;
        fout<<cmmdc(a, b)<<"\n";
    }
    return 0;
}
