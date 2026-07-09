#include <bits/stdc++.h>
using namespace std;
#define ll long long

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

ll gcd(ll a, ll b){
        if(a==0) return b;
        return gcd(b%a, a);
}

int main(){

        ll t,a,b;
        fin >> t;
        while(t--){
                fin >> a >> b;
                fout << gcd(a,b) << '\n';
        }

}
