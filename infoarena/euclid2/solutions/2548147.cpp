#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n;

int cmmdc(int a, int b){
    if(!b)
        return a;
    return cmmdc(b, a%b);
}

int main(){
    fin>>n;
    for(;n; n--){
        int x, y; fin>>x>>y;
        fout<<cmmdc(x, y)<<'\n';
    }

    return 0;
}
