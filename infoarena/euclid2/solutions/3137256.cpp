#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int Q, a, b;

int solve(int a, int b){
    return __gcd(a, b);
}

int main(){

    ios :: sync_with_stdio(false);
    fin.tie(0);
    fout.tie(0);

    fin >> Q;

    while(Q--){
        fin >> a >> b;
        fout << solve(a, b) << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}
