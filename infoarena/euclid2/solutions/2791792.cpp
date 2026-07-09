#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int v[100001], s[100001], d[100001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, r;
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> s[i] >> d[i];
        while(d[i]){
            r = s[i] % d[i];
            s[i] = d[i];
            d[i] = r;
        }
        v[i] = s[i];
    }
    for(int i = 1; i <= n; i++){
        fout << v[i] << '\n';
    }
    return 0;
}