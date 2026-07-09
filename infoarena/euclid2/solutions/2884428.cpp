#include <bits/stdc++.h>
#define ll long long
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int main(){
    ios_base::sync_with_stdio(false);
    int t; fin >> t;
    while (t--){
        int a , b; fin >> a >> b;
        fout << __gcd(a , b) << '\n';
    }
}
