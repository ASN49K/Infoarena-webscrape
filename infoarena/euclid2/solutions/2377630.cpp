#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int k;
int gcd(a, b){
    if (!b)
       return a;
    else
       return gcd(b, a mod b);
}
int main(){
    fin>>k;
    int a,b;
    while(k){
        fin>>a>>b;
        fout<<gcd(a,b)<<"\n";
        k--;
    }
    return 0;
}
