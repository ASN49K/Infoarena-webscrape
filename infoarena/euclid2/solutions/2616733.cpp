#include <bits/stdc++.h>
using namespace std;
#define ll long long

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main(){

        ll t,a,b;
        fin >> t;
        while(t--){
                fin >> a >> b;
                fout << __gcd(a,b) << '\n';
        }

}
